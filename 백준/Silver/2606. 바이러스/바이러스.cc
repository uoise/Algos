#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grp;
vector<bool> vst;
int n, m, cnt;
void dfs(int cur) {
  vst[cur] = true;
  cnt++;
  for (int i = 0; i < grp[cur].size(); i++) {
    int nxt = grp[cur][i];
    if (vst[nxt] == false) dfs(nxt);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  int x, y;
  grp.resize(n + 1);
  vst.resize(n + 1);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  dfs(1);
  printf("%d", --cnt);
}