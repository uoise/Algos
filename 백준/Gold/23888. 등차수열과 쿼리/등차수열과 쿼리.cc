#include <cstdio>
int a, d, q, o, s, e;
long long sum(int n) { return (n * (2LL * a + (n - 1) * d)) / 2LL; }
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  scanf("%d %d %d", &a, &d, &q);
  while (q--) {
    scanf("%d %d %d", &o, &s, &e);
    printf("%lld\n", o == 1 ? sum(e) - sum(s - 1)
                            : (s == e ? a + d * (s - 1) : gcd(a, d)));
  }
}