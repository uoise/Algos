#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 201, INF = 0x3f3f3f3f;
int n, m, vv[MX][MX], pv[MX][MX];
int main() {
  memset(vv, 0x3f, sizeof vv);
  scanf("%d %d", &n, &m);
  int x, y, z;
  while (m--) {
    scanf("%d %d %d", &x, &y, &z);
    vv[x][y] = std::min(vv[x][y], z);
    vv[y][x] = std::min(vv[y][x], z);
    pv[x][y] = y, pv[y][x] = x;
  }
  for (y = 1; y <= n; y++)
    for (x = 1; x <= n; x++)
      for (z = 1; z <= n; z++) {
        if (x == y || y == z || vv[x][y] >= INF || vv[y][z] >= INF) continue;
        if (vv[x][z] <= vv[x][y] + vv[y][z]) continue;
        vv[x][z] = vv[x][y] + vv[y][z];
        pv[x][z] = pv[x][y];
      }
  for (x = 1; x <= n; x++) {
    for (y = 1; y <= n; y++) {
      if (x == y) printf("- ");
      else printf("%d ", pv[x][y]);
    }
    printf("\n");
  }
}