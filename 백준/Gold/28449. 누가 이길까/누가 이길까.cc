#include <algorithm>
#include <cstdio>

constexpr int MN = 1e5 + 1;
long long x, y, z;
int n, m, a[MN], b[MN];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  std::sort(a, a + n), std::sort(b, b + m);
  for (int i = 0; i < n; i++) {
    auto lb = std::lower_bound(b, b + m, a[i]);
    auto ub = std::upper_bound(b, b + m, a[i]);
    x += lb - b, y += b + m - ub, z += ub - lb;
  }
  printf("%lld %lld %lld", x, y, z);
}