#include <iostream>
int max(const int& a, const int& b) { return a > b ? a : b; }
int N, K, W[101], V[101], dp[101][100001];
int solve() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= K; j++)
      if (W[i] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
  return dp[N][K];
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) scanf("%d %d", &W[i], &V[i]);
  printf("%d\n", solve());
}