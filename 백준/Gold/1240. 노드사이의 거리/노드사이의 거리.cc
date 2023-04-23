#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 1001, INF = 0x3F3F3F3F;
int n, m, vv[MX][MX];
int main() {
  int u, v, c;
  memset(vv, 0x3f, sizeof vv);
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &u, &v, &c);
    vv[u][v] = std::min(vv[u][v], c);
    vv[v][u] = std::min(vv[v][u], c);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        vv[j][k] = std::min(vv[j][k], vv[j][i] + vv[i][k]);
      }
    }
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    printf("%d\n", vv[u][v]);
  }
}