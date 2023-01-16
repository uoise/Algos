#include <cstdio>
long long dp[91] = {0, 1, 1, 2, 3};
int n;
int main() {
  scanf("%d", &n);
  for (int i = 4; i <= n; i++) {
    dp[i] = 1;
    for (int j = i - 2; j; j--) dp[i] += dp[j];
  }
  printf("%lld", dp[n]);
}