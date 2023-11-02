#include <cstdio>

using ll = long long;

ll x, y;
ll xgd(ll a, ll n) {
  if (!n) {
    x = 1, y = 0;
    return a;
  }

  ll g = xgd(n, a % n), t = y;
  y = x - (a / n) * y;
  x = t;
  if (x < 0) x += n, y -= a;

  return g;
}

int main() {
  ll n, a;
  scanf("%lld %lld", &n, &a);
  printf("%lld %lld", n - a, xgd(a, n) == 1 ? x : -1);
}