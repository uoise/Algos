#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

constexpr int MX = 1e4 + 1;
std::vector<int> ev[MX], rv;
int n, dp[MX][2], bv[MX];
void dfs(int c) {
  bv[c] = 1;
  for (const int& a : ev[c]) {
    if (bv[a]) continue;
    dfs(a);
    dp[c][0] += std::max(dp[a][0], dp[a][1]);
    dp[c][1] += dp[a][0];
  }
}

void fnd(int b, int c) {
  bv[c] = -1;
  if (bv[b] != 1 && (dp[c][1] > dp[c][0])) {
    bv[c] = 1;
    rv.push_back(c);
  }
  for (const int& a : ev[c]) if (!bv[a]) fnd(c, a);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &dp[i][1]);
  for (int i = 1; i < n; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    ev[s].push_back(e);
    ev[e].push_back(s);
  }
  dfs(1);
  printf("%d\n", std::max(dp[1][0], dp[1][1]));
  memset(bv, 0, sizeof bv);
  fnd(0, 1);
  std::sort(rv.begin(), rv.end());
  for (const int& r : rv) printf("%d ", r);
}