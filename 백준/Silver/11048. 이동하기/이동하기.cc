#include <algorithm>
#include <cstdio>

constexpr int MX = 1001;
int n, m, v[MX][MX], dp[MX][MX];
int main() {
  scanf("%d %d", &n, &m);
  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= m; x++) scanf("%d", &v[y][x]);
  for (int y = 0; y <= n; y++) {
    for (int x = 0; x <= m; x++) {
      if (x + 1 <= m)
        dp[y][x + 1] = std::max(dp[y][x + 1], dp[y][x] + v[y][x + 1]);
      if (y + 1 <= n)
        dp[y + 1][x] = std::max(dp[y + 1][x], dp[y][x] + v[y + 1][x]);
      if (y + 1 <= n && x + 1 <= m)
        dp[y + 1][x + 1] =
            std::max(dp[y + 1][x + 1], dp[y][x] + v[y + 1][x + 1]);
    }
  }
  printf("%d", dp[n][m]);
}