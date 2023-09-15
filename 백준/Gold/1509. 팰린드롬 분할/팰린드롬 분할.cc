#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 2502, INF = 0x3f3f3f3f;

int n, dp[MX];
bool pv[MX][MX];
char c[MX];
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int i = 1; i <= n; i++) {
    pv[i][i] = true;
    if (c[i - 1] == c[i]) pv[i - 1][i] = true;
  }

  for (int l = 3; l <= n; l++) {
    for (int s = 1; s + l - 1 <= n; s++) {
      int e = s + l - 1;
      if ((c[s] == c[e]) && pv[s + 1][e - 1]) pv[s][e] = true;
    }
  }

  for (int e = 1; e <= n; e++) {
    dp[e] = INF;
    for (int s = 1; s <= e; s++) if (pv[s][e]) dp[e] = std::min(dp[e], dp[s - 1] + 1);
  }

  printf("%d", dp[n]);
}