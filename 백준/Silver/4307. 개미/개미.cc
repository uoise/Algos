#include <algorithm>
#include <cstdio>

void sol() {
  int n, l, p, s = 1e7, m = 0, e = 0, x;
  scanf("%d %d", &l, &n);
  p = l / 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    s = std::min(s, x);
    e = std::max(e, x);
    m = std::abs(p - m) > std::abs(p - x) ? x : m;
  }
  printf("%d %d\n", std::min(l - m, m), std::max(l - s, e));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}