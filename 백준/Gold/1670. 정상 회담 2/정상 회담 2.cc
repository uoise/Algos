#include <cstdio>

long long dp[10001], MX = 987654321;
int n;
int main() {
  scanf("%d", &n);
  dp[0] = dp[2] = 1;
  for (int i = 4; i <= n; i++)
    for (int j = 0; j < i; j += 2) dp[i] = (dp[i] + dp[j] * dp[i - j - 2]) % MX;
  printf("%d", dp[n]);
}