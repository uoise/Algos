#include <iostream>
int n, m, v[501][501], dp[501][501];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
  if (x == n && y == m) return 1;
  if (dp[x][y] != -1) return dp[x][y];
  dp[x][y] = 0;
  for (int i = 0; i < 4; i++) {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
    if (v[tx][ty] < v[x][y]) dp[x][y] += dfs(tx, ty);
  }
  return dp[x][y];
}

int main() {
  scanf("%d %d", &n, &m);
  for (int x = 1; x <= n; x++)
    for (int y = 1; y <= m; y++) {
      scanf("%d", &v[x][y]);
      dp[x][y] = -1;
    }
  printf("%d\n", dfs(1, 1));
}
