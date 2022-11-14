#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using iip = pair<int, int>;
constexpr int MX = 1001, INF = 0x3f3f3f3f;
vector<vector<iip>> grp(MX);
vector<iip> dst(MX, {INF, 0});
int n, m, bb, ee, cnt;
bool prt = false;

void sol() {
  priority_queue<iip, vector<iip>, greater<iip>> pq;
  dst[bb] = {0, 0};
  pq.push({0, bb});
  while (!pq.empty()) {
    const int ctx = pq.top().second, cst = pq.top().first;
    pq.pop();
    if (ctx == ee) break;
    for (const auto& nxt : grp[ctx]) {
      if (dst[nxt.first].first > cst + nxt.second) {
        dst[nxt.first].first = cst + nxt.second;
        dst[nxt.first].second = ctx;
        pq.push({dst[nxt.first].first, nxt.first});
      }
    }
  }
  vector<int> res;
  int cur = ee;
  while (cur != 0) {
    res.push_back(cur);
    cur = dst[cur].second;
  }
  cout << dst[ee].first << '\n';
  cout << res.size() << '\n';
  for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  int b, e, w;
  for (int i = 0; i < m; i++) {
    cin >> b >> e >> w;
    grp[b].push_back({e, w});
  }
  for (int i = 1; i <= n; i++) sort(grp[i].begin(), grp[i].end());
  cin >> bb >> ee;
  sol();
}
