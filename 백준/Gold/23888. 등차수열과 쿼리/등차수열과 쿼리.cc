#include <cstdio>
using ll = long long;
int q, o;
ll a, d, s, e;
ll sum(ll n) { return (n * (2LL * a + (n - 1) * d)) / 2LL; }
ll gcd(long x, ll y) { return y ? gcd(y, x % y) : x; }
int main() {
  scanf("%lld %lld %d", &a, &d, &q);
  while (q--) {
    scanf("%d %lld %lld", &o, &s, &e);
    printf("%lld\n", o == 1 ? sum(e) - sum(s - 1)
                            : (s == e ? a + d * (s - 1) : gcd(a, d)));
  }
}