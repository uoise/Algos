#include <algorithm>
#include <cstdio>
#include <cstring>

int rv[101][101], n, m, r, v = 2e9;
int main() {
  memset(rv, 0x3f, sizeof rv);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    rv[y][x] = rv[x][y] = 1;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (j != k && j != i)
          rv[j][k] = std::min(rv[j][k], rv[j][i] + rv[i][k]);

  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 1; j <= n; j++)
      if (j != i) s += rv[i][j];
    if (s < v) v = s, r = i;
  }
  printf("%d", r);
}