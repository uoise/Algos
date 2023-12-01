#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

int n, m, vv[21][21], dp[2097153];
int bcnt(int x) {
  int r = 0;
  while (x) {
    r += x & 1;
    x >>= 1;
  }
  return r;
}

int main() {
  memset(dp, 0x3f, sizeof dp);
  scanf("%d", &n);
  m = pow(2, n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%d", &vv[y][x]);
  dp[0] = 0;
  for (int i = 0; i < m; i++) {
    int t = bcnt(i);
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j)))
        dp[i | (1 << j)] = std::min(dp[i | (1 << j)], dp[i] + vv[t][j]);
    }
  }
  printf("%d", dp[m - 1]);
}