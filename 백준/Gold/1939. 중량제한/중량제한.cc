#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
constexpr int MX = 1e4 + 1;
vector<vector<pair<int, int>>> grp;
int n, bi, ei;
int bv[MX];

void inp() {
  int m, x, y, w;
  cin >> n >> m;
  grp.assign(n + 1, vector<pair<int, int>>());
  while (m--) {
    cin >> x >> y >> w;
    grp[x].push_back({w, y});
    grp[y].push_back({w, x});
  }
  for (auto& v : grp) sort(v.begin(), v.end(), greater<>());
  cin >> bi >> ei;
}

int sol() {
  priority_queue<pair<int, int>> pq;
  bv[bi] = 2e9;
  pq.push({bv[bi], bi});
  while (!pq.empty()) {
    int wht = pq.top().first, cur = pq.top().second;
    if (cur == ei) return bv[ei];
    pq.pop();
    for (const auto& p : grp[cur]) {
      int cst = min(wht, p.first);
      if (bv[p.second] < cst) {
        bv[p.second] = cst;
        pq.push({bv[p.second], p.second});
      }
    }
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  inp();
  cout << sol();
}
