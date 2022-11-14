#include <iostream>
#include <vector>

using namespace std;
constexpr int MX = 1'000'001;
int n, bv[MX], rv[MX];
vector<int> vv[MX];

int dfs(int cur) {
  bv[cur] = vv[cur].size();
  for (const auto& nxt : vv[cur]) {
    if (!bv[nxt]) {
      if (!dfs(nxt)) --bv[cur];
    }
  }
  rv[cur] = vv[cur].size() - bv[cur];
  return rv[cur];
}

int sol() {
  int a, b;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    vv[a].push_back(b);
    vv[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    if (!bv[i]) dfs(i);
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (rv[i]) res++;
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}
