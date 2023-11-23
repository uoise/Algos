#include <cstdio>
bool dp[1001];
int n;
int main() {
  scanf("%d", &n);
  dp[1] = dp[3] = 1;
  for (int i = 4; i <= n; i++) dp[i] = !(dp[i - 1] || dp[i - 3]);
  printf("%s", dp[n] ? "CY" : "SK");
}