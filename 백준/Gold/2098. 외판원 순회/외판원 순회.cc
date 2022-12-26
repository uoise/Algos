#include <algorithm>
#include <cstdio>

constexpr int INF = 2e9, SZ = 17, MX = 1 << (SZ - 1);
int n, w[SZ][SZ], dp[SZ][MX];
int tsp(int cur, int vst) {
  if (vst == (1 << n) - 1) return w[cur][0] ? w[cur][0] : INF;
  int& cdp = dp[cur][vst];
  if (cdp) return cdp;
  cdp = INF;
  for (int i = 0; i < n; i++) {
    if (vst & (1 << i)) continue;
    if (w[cur][i]) {
      int tpr = tsp(i, vst | (1 << i));
      if (tpr >= INF) continue;
      cdp = std::min(cdp, tpr + w[cur][i]);
    }
  }
  return cdp;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &w[i][j]);
  printf("%d", tsp(0, 1));
}