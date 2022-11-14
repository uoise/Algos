#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> vv;
vector<int> vb;
void sol(const int cur) {
  int idx = 0;
  while (idx < vv[cur].size()) {
    if (vb[vv[cur][idx]]) {
      vv[cur].erase(vv[cur].begin() + idx);
      continue;
    }
    vb[vv[cur][idx]] = cur;
    sol(vv[cur][idx++]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vv.assign(n + 1, vector<int>());
  vb.assign(n + 1, 0);
  vb[1] = 1;
  int a, b;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    vv[a].push_back(b);
    vv[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) sort(vv[i].begin(), vv[i].end());
  sol(1);
  for (int i = 2; i <= n; i++) cout << vb[i] << '\n';
}