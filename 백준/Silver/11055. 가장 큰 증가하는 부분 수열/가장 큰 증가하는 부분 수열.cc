#include <cstdio>

constexpr int MX = 1001;
int n, vv[MX], dp[MX], r;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &vv[i]);
  for (int i = 1; i <= n; i++) {
    dp[i] = vv[i];
    for (int j = 1; j < i; j++)
      if (vv[j] < vv[i] && dp[i] < dp[j] + vv[i]) dp[i] = dp[j] + vv[i];
    if (r < dp[i]) r = dp[i];
  }

  printf("%d", r);
}