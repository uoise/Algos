#include <cstdio>

bool a[100001];
int v[1 << 21];
int init(int n, int b, int e) {
  return v[n] = (b == e) ? a[b]
                         : init(n * 2, b, (b + e) / 2) +
                               init(n * 2 + 1, (b + e) / 2 + 1, e);
}

int mod(int n, int b, int e, int i, int x) {
  if (i < b || i > e) return v[n];
  return v[n] = (b == e) ? x
                         : mod(n * 2, b, (b + e) / 2, i, x) +
                               mod(n * 2 + 1, (b + e) / 2 + 1, e, i, x);
}

int qry(int n, int b, int e, int l, int r) {
  if (l > e || r < b) return 0;
  return (l <= b && r >= e) ? v[n]
                            : qry(n * 2, b, (b + e) / 2, l, r) +
                                  qry(n * 2 + 1, (b + e) / 2 + 1, e, l, r);
}

int main() {
  int n, m, o, s, e, r;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s);
    a[i] = s & 1;
  }

  scanf("%d", &m);
  init(1, 1, n);
  while (m--) {
    scanf("%d %d %d", &o, &s, &e);
    if (o == 1) {
      e = e & 1;
      if (a[s] != e) mod(1, 1, n, s, a[s] = e);
    } else {
      r = qry(1, 1, n, s, e);
      printf("%d\n", o == 2 ? e - s + 1 - r : r);
    }
  }
}