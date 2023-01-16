#include <cstdio>
int n, v[1001], dp[1001];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    dp[i] = v[i];
    for (int j = 1; j < i; j++)
      if (dp[i] < dp[j] + v[i - j]) dp[i] = dp[j] + v[i - j];
  }
  printf("%d", dp[n]);
}