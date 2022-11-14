#include <cstring>
#include <iostream>

using namespace std;
string s1, s2;

void sol() {
  const int n = s1.size(), m = s2.size();
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  cout << dp[n][m] << '\n';
  if (dp[n][m] == 0) return;

  int idx = dp[n][m], cn = n, cm = m;
  char r[idx];
  while (idx) {
    if (dp[cn - 1][cm] == idx)
      cn--;
    else if (dp[cn][cm - 1] == idx)
      cm--;
    else {
      r[--idx] = s1[cn - 1];
      cm--, cn--;
    }
  }
  for (const auto& c : r) cout << c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s1 >> s2;
  sol();
}
