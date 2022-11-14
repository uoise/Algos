#include <iostream>
using namespace std;
string N, M;
int dp[1001][1001];
int max(const int a, const int b) { return a > b ? a : b; }
int solve() {
  int n = N.size(), m = M.size();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (N[i - 1] == M[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  return dp[n][m];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  cout << solve() << '\n';
}