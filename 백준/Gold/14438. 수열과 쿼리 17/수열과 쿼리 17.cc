#include <algorithm>
#include <cstdio>

int a[100001], v[1 << 21];
int init(int n, int b, int e) {
  return v[n] = (b == e) ? a[b]
         : std::min(init(n * 2, b, (b + e) / 2),
                    init(n * 2 + 1, (b + e) / 2 + 1, e));
}

int mod(int n, int b, int e, int i, int x) {
  if (i < b || i > e) return v[n];
  return v[n] = (b == e) ? x
         : std::min(mod(n * 2, b, (b + e) / 2, i, x),
                    mod(n * 2 + 1, (b + e) / 2 + 1, e, i, x));
}

int qry(int n, int b, int e, int l, int r) {
  if (l > e || r < b) return 1e9 + 1;
  return (l <= b && r >= e) ? v[n]
         : std::min(qry(n * 2, b, (b + e) / 2, l, r),
                    qry(n * 2 + 1, (b + e) / 2 + 1, e, l, r));
}

int main() {
  int n, m, o, s, e;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  init(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d %d", &o, &s, &e);
    if (o == 1) mod(1, 1, n, s, e);
    else printf("%d\n", qry(1, 1, n, s, e));
  }
}