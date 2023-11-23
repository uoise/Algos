#include <cstdio>
bool dp[1001];
int n;
int main() {
  scanf("%d", &n);
  dp[2] = dp[4] = dp[5] = 1;
  for (int i = 6; i <= n; i++) dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);
  printf("%s", dp[n] ? "SK" : "CY");
}