#include <cstdio>
int n, dp[100001] = {1, 3};
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
  printf("%d", dp[n]);
}