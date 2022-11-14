#include <cmath>
#include <iostream>
using namespace std;
int n, m, q, w[31];
bool dp[31][15001];
void init(int idx, int wgt) {
  if (idx > n || dp[idx][wgt]) return;
  dp[idx][wgt] = true;
  init(idx + 1, wgt + w[idx]);
  init(idx + 1, abs(wgt - w[idx]));
  init(idx + 1, wgt);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i];
  init(0, 0);

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> q;
    if (q > 15000 || !dp[n][q])
      cout << "N ";
    else
      cout << "Y ";
  }
}