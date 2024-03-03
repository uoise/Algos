#include <cstdio>

using ll = long long;

ll a, b, c, d, k;
ll rmd(ll x, ll y) { return x / y + (x % y ? 1LL : 0LL); }
ll sol() {
  if (!k) {
    ll l = rmd(a, b), r = rmd(a + c, d);
    return l < r ? l : -1LL;
  }

  ll l = 1, t = rmd(a + c, d), r = rmd(b, k);
  if (r * b - r * (r - 1) * k / 2 < a) return -1LL;

  while (l < r) {
    ll m = (l + r) / 2;
    if (m * b - m * (m - 1) * k / 2 < a) l = m + 1;
    else r = m;
  }

  return l < t ? l : -1LL;
}

int main() {
  scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &k);
  printf("%lld", sol());
}