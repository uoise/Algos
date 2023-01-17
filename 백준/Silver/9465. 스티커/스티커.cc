#include <algorithm>
#include <cstdio>

using namespace std;

constexpr int sz = 1e5 + 1;
int T, n, dp[sz][2];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int j = 0; j < 2; j++)
      for (int i = 1; i <= n; i++) scanf("%d", &dp[i][j]);
    for (int i = 2; i <= n; i++) {
      dp[i][0] += max(dp[i - 1][1], dp[i - 2][1]);
      dp[i][1] += max(dp[i - 1][0], dp[i - 2][0]);
    }
    printf("%d\n", max(dp[n][0], dp[n][1]));
  }
}