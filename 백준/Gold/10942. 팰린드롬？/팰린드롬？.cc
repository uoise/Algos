#include <iostream>
using namespace std;
int dp[2001][2001], v[2001];
int sol(int stt, int end) {
  if (stt > end) return 0;
  if (stt == end) return 1;
  int& res = dp[stt][end];
  if (dp[stt][end] != 0) return res;

  if (v[stt] == v[end]) {
    if (stt + 1 == end)
      res = v[stt];
    else if (stt + 2 == end)
      res = v[stt + 1];
    else
      res = sol(stt + 1, end - 1);
  }
  return dp[stt][end] = res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int s, e, n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> s >> e;
    if (sol(s, e) > 0)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
}
