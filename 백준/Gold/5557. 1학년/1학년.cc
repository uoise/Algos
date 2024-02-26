#include <cstdio>

constexpr int MX = 21;

long long dp[101][MX];
int n, v[101];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  dp[0][v[0]] = 1;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 0; j < MX; j++) {
      if (j + v[i] >= 0 && j + v[i] < MX) dp[i][j] += dp[i - 1][j + v[i]];
      if (j - v[i] >= 0 && j - v[i] < MX) dp[i][j] += dp[i - 1][j - v[i]];
    }
  }
  printf("%lld", dp[n - 2][v[n - 1]]);
}