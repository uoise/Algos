#include <algorithm>
#include <cstdio>
#include <cstring>

int v[301][301], d[301][301];
int main() {
  int n, m, k, a, b, c, r = 0;
  scanf("%d %d %d", &n, &m, &k);
  memset(d, -1, sizeof d);
  while (k--) {
    scanf("%d %d %d", &a, &b, &c);
    if (a < b) v[a][b] = std::max(v[a][b], c);
  }
  d[1][1] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k < j; k++)
        if (v[j - k][j] && d[i - 1][j - k] != -1)
          d[i][j] = std::max(d[i][j], d[i - 1][j - k] + v[j - k][j]);
  for (int i = 0; i <= m; i++) r = std::max(r, d[i][n]);
  printf("%d", r);
}