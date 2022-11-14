#include <algorithm>
#include <iostream>
#include <vector>
#define MX 100001
using namespace std;
vector<vector<int>> grp;
vector<int> vst, seq;
int n, m, r, cnt;
void dfs(int cur) {
  vst[cur] = 1;
  seq[cur] = ++cnt;

  for (int i = 0; i < grp[cur].size(); i++)
    if (vst[grp[cur][i]] == 0) dfs(grp[cur][i]);
}
int main() {
  scanf("%d %d %d", &n, &m, &r);
  grp.resize(n + 1);
  vst.resize(n + 1);
  seq.resize(n + 1);
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) sort(grp[i].begin(), grp[i].end(), greater<int>());
  dfs(r);
  for (int i = 1; i <= n; i++) printf("%d\n", seq[i]);
}