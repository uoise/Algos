#include <cstdio>
constexpr int MX = 1e9 + 7;
int n, dp[3][1516];
int main() {
  scanf("%d", &n);
  dp[0][2] = dp[1][2] = 1, dp[2][2] = 0;
  for (int i = 3; i <= n; i++)
    for (int j = 0; j < 3; j++)
      dp[j][i] = (dp[(j + 2) % 3][i - 1] + dp[(j + 1) % 3][i - 1]) % MX;
  printf("%d", dp[0][n]);
}