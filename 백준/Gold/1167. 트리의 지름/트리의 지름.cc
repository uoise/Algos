#include <iostream>
#include <vector>
#define iip pair<int, int>
using namespace std;
vector<vector<iip>> vv;
vector<int> vs;
int V;
void dfs(const int cur, const int cst) {
  if (vs[cur] == 0) vs[cur] = -1;
  for (const auto& nxt : vv[cur]) {
    if (vs[nxt.first] == 0) {
      if (nxt.second + cst > vs[nxt.first]) vs[nxt.first] = nxt.second + cst;
      dfs(nxt.first, nxt.second + cst);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> V;
  vv.assign(V + 1, vector<iip>());

  int cur, nxt = 0, cst;
  for (int i = 1; i <= V; i++) {
    cin >> cur;
    while (1) {
      cin >> nxt;
      if (nxt == -1) break;
      cin >> cst;
      vv[cur].push_back({nxt, cst});
    }
  }

  cst = 0, cur = 1;
  vs.assign(V + 1, 0);
  dfs(cur, 0);
  for (int i = 1; i <= V; i++)
    if (vs[i] > cst) {
      cst = vs[i];
      cur = i;
    }
  vs.assign(V + 1, 0);
  dfs(cur, 0);
  for (int i = 1; i <= V; i++)
    if (vs[i] > cst) cst = vs[i];
  cout << cst;
}