#include <algorithm>
#include <cstdio>

constexpr int MX = 1e5 + 1;
int m, n, l, x, y, v[MX], r;
int sol(int s, int e, const int lft) {
  while (s <= e) {
    int m = (s + e) / 2;
    if (std::abs(v[m] - x) + y <= l)
      return 1;
    else if (v[m] < lft)
      s = m + 1;
    else
      e = m - 1;
  }
  return 0;
}

int main() {
  scanf("%d %d %d", &m, &n, &l);
  for (int i = 0; i < m; i++) scanf("%d", &v[i]);
  std::sort(v, v + m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    if (y <= l) r += sol(0, m - 1, x - l + y);
  }
  printf("%d", r);
}