#include <algorithm>
#include <cstdio>

constexpr int MX = 1e8;
int n, x, y, nm = MX, nx = -MX, pm = MX, px = -MX;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    nm = std::min(nm, y - x);
    nx = std::max(nx, y - x);
    pm = std::min(pm, y + x);
    px = std::max(px, y + x);
  }
  printf("%d", std::max(nx - nm, px - pm));
}