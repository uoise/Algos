#include <algorithm>
#include <cstdio>
#include <cstring>

int n, x, dp[100001];
int main() {
  memset(dp, 0x3f, sizeof dp);
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) dp[i] = i;
  for (int i = 2; i * i <= n; i++) {
    x = i * i;
    dp[x] = 1;
    for (int j = 2; x * j <= n; j++) dp[x * j] = std::min(dp[x * j], j);
    for (int j = 1; (j <= x) && (x + j <= n); j++)
      dp[j + x] = std::min(dp[j + x], dp[j] + 1);
  }
  printf("%d", dp[n]);
}