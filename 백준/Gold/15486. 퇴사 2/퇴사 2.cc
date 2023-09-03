#include <algorithm>
#include <cstdio>

constexpr int MX = 15e5 + 2;

int dp[MX], n, t, p;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &t, &p);
    dp[i] = std::max(dp[i], dp[i - 1]);
    if (i + t > n + 1) continue;
    dp[i + t] = std::max(dp[i + t], dp[i] + p);
  }
  for (int i = 1; i <= n + 1; i++) dp[i] = std::max(dp[i], dp[i - 1]);

  printf("%d", dp[n + 1]);
}