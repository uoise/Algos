#include <iostream>
#include <vector>
using namespace std;
int n, w;
vector<pair<int, int>> ww;
vector<vector<int>> dp;

int len(const int i1, const int i2) {
  if (i1 == 0) return abs(ww[i2].first - 1) + abs(ww[i2].second - 1);
  if (i2 == 0) return abs(n - ww[i1].first) + abs(n - ww[i1].second);
  return abs(ww[i1].first - ww[i2].first) + abs(ww[i1].second - ww[i2].second);
}

int sol(const int i1, const int i2) {
  const int iw = max(i1, i2) + 1;
  if (iw > w) return 0;
  if (dp[i1][i2] != -1) return dp[i1][i2];
  const int l1 = len(i1, iw), l2 = len(iw, i2);
  return dp[i1][i2] = min(sol(iw, i2) + l1, sol(i1, iw) + l2);
}

void sln() {
  int cw = 0, c1 = 0, c2 = 0, l1, l2;
  while (cw < w) {
    cw = max(c1, c2) + 1;
    l1 = len(c1, cw), l2 = len(cw, c2);
    if (dp[cw][c2] + l1 > dp[c1][cw] + l2) {
      cout << "2\n";
      c2 = cw;
    } else {
      cout << "1\n";
      c1 = cw;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> w;
  int x, y;
  ww.assign(w + 1, {0, 0});
  dp.assign(w + 1, vector<int>(w + 1, -1));
  for (int i = 1; i <= w; i++) {
    cin >> x >> y;
    ww[i] = {x, y};
  }
  cout << sol(0, 0) << '\n';
  sln();
}