#include <cstdio>
#include <cstring>

int n, m, x, k, v[100], dp[10001];
int main() {
  scanf("%d %d", &n, &k);
  memset(dp, 0x3f, sizeof dp);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x <= k) v[m++] = x, dp[x] = 1;
  }

  for (int i = 0; i < m; i++) {
    for (int j = v[i]; j <= k; j++) {
      x = dp[j - v[i]] + 1;
      if (x < dp[j]) dp[j] = x;
    }
  }
  printf("%d", dp[k] == 0x3f3f3f3f ? -1 : dp[k]);
}