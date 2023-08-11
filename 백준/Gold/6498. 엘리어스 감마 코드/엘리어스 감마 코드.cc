#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 129, INF = 0x3f3f3f3f;
int n, v[MX], dp[MX][MX];
int sol() {
  int r = INF, s;
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    s = 0;
    for (int m = i; m; m--) {
      s += v[m];
      for (int j = 1; j <= i; j++)
        dp[i][j] = std::min(dp[i][j], dp[m - 1][j - 1] + (i + j) * s);
    }
  }

  for (int i = 1; i <= n; ++i) r = std::min(r, dp[n][i]);
  return r;
}

int main() {
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    printf("%d\n", sol());
  }
}