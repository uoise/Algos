#include <cstdio>

int n, r = 2, dp[31] = {1, 0, 3};
int main() {
  scanf("%d", &n);
  for (int i = 4; i <= n; i += 2) {
    dp[i] = dp[i - 2] * 3 + r;
    r += dp[i - 2] * 2;
  }
  printf("%d", dp[n]);
}