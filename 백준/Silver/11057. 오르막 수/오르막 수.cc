#include <cstdio>

int dp[1002][11], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 10; i++) dp[1][i] = i;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= 10; j++)
      dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
  printf("%d", dp[n][10]);
}