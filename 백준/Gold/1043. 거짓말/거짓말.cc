#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> hv, pv;
int n, m;

void inp() {
  int t, x;
  cin >> n >> m;
  hv.assign(n + 1, vector<int>());
  pv.assign(m + 1, vector<int>());
  hv[0].assign(n + 1, 0);  // hmn tf
  pv[0].assign(m + 1, 1);  // pty cnt

  cin >> x;
  while (x--) {
    cin >> t;
    hv[0][t] = 1;
  }

  for (int i = 1; i <= m; i++) {
    cin >> x;
    pv[i].resize(x);
    for (int j = 0; j < x; j++) {
      cin >> t;
      pv[i][j] = t;
      hv[t].push_back(i);
    }
  }
}

void dfs(int cpt) {
  if (!pv[0][cpt]) return;
  pv[0][cpt] = 0;
  for (const auto& h : pv[cpt]) {
    if (!hv[0][h]) {
      hv[0][h] = 1;
      for (const auto& p : hv[h]) dfs(p);
    }
  }
}

int sol() {
  for (int h = 1; h <= n; h++) {
    if (hv[0][h])
      for (const auto& p : hv[h]) dfs(p);
  }

  int res = m;
  for (const auto& i : pv[0])
    if (!i) res--;
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  inp();
  cout << sol();
}