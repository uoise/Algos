#include <cstdio>

constexpr int MX = 1e9;
int n, k, dp[201][201];
int main() {
  scanf("%d %d", &n, &k);
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 0; j <= n; j++)
      for (int l = 0; l <= j; l++)
        dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MX;
  printf("%d", dp[k][n]);
}