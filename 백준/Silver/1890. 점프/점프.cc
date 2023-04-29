#include <cstdio>
int n, v[100][100];
long long dp[100][100];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &v[i][j]);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (!v[i][j]) continue;
      if (v[i][j] + i < n) dp[v[i][j] + i][j] += dp[i][j];
      if (v[i][j] + j < n) dp[i][v[i][j] + j] += dp[i][j];
    }
  printf("%lld", dp[n - 1][n - 1]);
}