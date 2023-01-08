#include <algorithm>
#include <cstdio>
int dp[50001], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int pw = j * j;
      if (pw > i) break;
      if (!dp[i])
        dp[i] = dp[i - pw] + 1;
      else
        dp[i] = std::min(dp[i], dp[i - pw] + 1);
    }
  }
  printf("%d", dp[n]);
}