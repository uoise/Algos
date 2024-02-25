#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 2e5;
int n, k, a[51], b[51], dp[101][MX];
int sol() {
  dp[0][1] = 0;
  for (int t = 0; t < k; t++) {
    for (int s = 1; s < MX; s++) {
      int& c = dp[t][s];
      if (c < 0) continue;
      dp[t + 1][s] = c + s;
      for (int i = 0; i < n; i++) {
        if (c < a[i]) continue;
        dp[t + 1][s + b[i]] = std::max(dp[t + 1][s + b[i]], c - a[i]);
      }
    }
  }

  int r = 0;
  for (int i = 0; i < MX; i++) r = std::max(r, dp[k][i]);
  return r;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
  memset(dp, -1, sizeof dp);
  printf("%d", sol());
}