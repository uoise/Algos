#include <algorithm>
#include <cstdio>
int n, dp[100001][2], r = -100000001;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &dp[i][0]);
    dp[i][1] = std::max(dp[i - 2][0], dp[i - 1][1]) + dp[i][0];
    dp[i][0] += dp[i - 1][0] < 1 ? 0 : dp[i - 1][0];
    r = std::max(r, std::max(dp[i][0], dp[i][1]));
  }
  printf("%d", r);
}