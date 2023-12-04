#include <algorithm>
#include <cstdio>
#include <vector>

constexpr int MX = 1e4 + 1;
std::vector<int> ev[MX];
int dp[MX][2], bv[MX];
void sol(int c) {
  bv[c] = 1;
  for (const int& n : ev[c]) {
    if (bv[n]) continue;
    sol(n);
    dp[c][0] += std::max(dp[n][0], dp[n][1]);
    dp[c][1] += dp[n][0];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &dp[i][1]);
  while (--n) {
    int s, e;
    scanf("%d %d", &s, &e);
    ev[s].push_back(e);
    ev[e].push_back(s);
  }
  sol(1);
  printf("%d", std::max(dp[1][0], dp[1][1]));
}