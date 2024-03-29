#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
void sol() {
  vector<vector<int>> vv(n + 1);
  vector<int> bv(n + 1, 0);
  queue<int> q;
  int u, v;
  while (m--) {
    cin >> u >> v;
    vv[u].push_back(v);
    ++bv[v];
  }
  u = n;
  while (u--) {
    for (int i = 1; i <= n; i++)
      if (!bv[i]) q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      cout << cur << ' ';
      for (const auto& nxt : vv[cur]) bv[nxt]--;
      bv[cur] = -1;
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  sol();
}