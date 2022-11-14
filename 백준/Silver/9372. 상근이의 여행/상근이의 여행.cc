#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> grp;
vector<bool> vst;

int mst(const int beg) {
  queue<int> q;
  q.push(beg);
  vst[beg] = 1;
  int r = 0;
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    for (const auto& nxt : grp[cur]) {
      if (!vst[nxt]) {
        vst[nxt] = 1;
        r++;
        q.push(nxt);
      }
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC, N, M, a, b;
  cin >> TC;
  while (TC--) {
    cin >> N >> M;
    grp.assign(N + 1, vector<int>());
    vst.assign(N + 1, 0);
    while (M--) {
      cin >> a >> b;
      grp[a].push_back(b);
      grp[b].push_back(a);
    }
    cout << mst(1) << '\n';
  }
}