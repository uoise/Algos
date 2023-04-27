#include <cstdio>
#include <cstring>

constexpr int MX = 401;

bool vv[MX][MX];
int n, m, u, v;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    vv[u][v] = 1;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (vv[j][i] && vv[i][k]) vv[j][k] = 1;

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    printf("%d\n", vv[u][v] ? -1 : (vv[v][u] ? 1 : 0));
  }
}