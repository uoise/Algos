#include <cstdio>
#include <unordered_map>

using ll = long long;

std::unordered_map<ll, ll> a;
ll n, p, q;
ll sol(ll c) {
  if (a[c]) return a[c];
  return a[c] = sol(c / p) + sol(c / q);
}

int main() {
  scanf("%lld %lld %lld", &n, &p, &q);
  a[0] = 1;
  printf("%lld", sol(n));
}