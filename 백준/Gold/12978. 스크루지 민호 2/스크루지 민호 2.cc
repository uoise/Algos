#include <algorithm>
#include <cstdio>
#include <vector>

constexpr int MX = 1e5 + 1;
std::vector<int> ev[MX];
int dp[MX][2], bv[MX];
void dfs(int c, int b) {
  dp[c][1] = bv[c] = 1;
  for (const int& n : ev[c]) {
    if (bv[n]) continue;
    dfs(n, c);
    dp[c][0] += dp[n][1];
    dp[c][1] += std::min(dp[n][0], dp[n][1]);
  }
}

int main() {
  int n, u, v;
  scanf("%d", &n);
  while (--n) {
    scanf("%d %d", &u, &v);
    ev[u].push_back(v);
    ev[v].push_back(u);
  }
  dfs(1, 0);
  printf("%d", std::min(dp[1][0], dp[1][1]));
}