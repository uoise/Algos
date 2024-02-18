#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MX = 5e5 + 1;
vector<int> res, vv[MX];
string univ[MX];
bool vst[MX], degree[MX];
void dfs(int c) {
  res.push_back(c);
  for (int a : vv[c]) if (!vst[a]) dfs(a);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> univ[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    vv[--u].push_back(--v);
    degree[v] = 1;
  }
  for (int i = 0; i < n; i++) if (!degree[i]) dfs(i);
  for (int idx : res) cout << univ[idx];
}