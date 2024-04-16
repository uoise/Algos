#include <cstdio>

long long v[1 << 21];
long long mod(int n, int b, int e, int i, long long x) {
  if (i < b || i > e) return v[n];
  if (b == e) return v[n] += x;
  return v[n] = mod(n * 2, b, (b + e) / 2, i, x) +
                mod(n * 2 + 1, (b + e) / 2 + 1, e, i, x);
}

long long qry(int n, int b, int e, int l, int r) {
  if (l > e || r < b) return 0;
  return (l <= b && r >= e) ? v[n]
                            : qry(n * 2, b, (b + e) / 2, l, r) +
                                  qry(n * 2 + 1, (b + e) / 2 + 1, e, l, r);
}

int main() {
  int n, Q, o, p;
  long long q;
  scanf("%d %d", &n, &Q);
  while (Q--) {
    scanf("%d %d %lld", &o, &p, &q);
    if (o == 1) mod(1, 1, n, p, q);
    else printf("%lld\n", qry(1, 1, n, p, q));
  }
}