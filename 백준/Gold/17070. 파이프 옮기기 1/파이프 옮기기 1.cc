#include <algorithm>
#include <cstdio>

int n, v[18][18];
void dfs(int y, int x, int d) {
  if (x > n || y > n || v[y][x] == -1) return;
  ++v[y][x];
  if (d ^ 1) dfs(y, x + 1, 0);
  if (d) dfs(y + 1, x, 1);
  if (v[y][x + 1] != -1 && v[y + 1][x] != -1) dfs(y + 1, x + 1, 2);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &v[i][j]);
      v[i][j] *= -1;
    }
  dfs(1, 2, 0);
  printf("%d", std::max(v[n][n], 0));
}