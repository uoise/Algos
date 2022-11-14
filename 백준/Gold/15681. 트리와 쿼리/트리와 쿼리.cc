#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> nv;
vector<int> pv, cv;

int dfs(const int cur) {
  for (const auto& nod : nv[cur]) {
    if (!pv[nod]) {
      pv[nod] = cur;
      cv[cur] += dfs(nod);
    }
  }
  return cv[cur];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, R, Q, u, v;
  cin >> N >> R >> Q;
  nv.assign(N + 1, vector<int>());
  pv.assign(N + 1, 0);
  cv.assign(N + 1, 1);
  pv[R] = -1;  // root
  for (int i = 1; i < N; i++) {
    cin >> u >> v;
    nv[u].push_back(v);
    nv[v].push_back(u);
  }
  dfs(R);
  while (Q--) {
    cin >> u;
    cout << cv[u] << " ";
  }
}