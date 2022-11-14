#include <string.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MX 1001
using namespace std;

vector<vector<int>> grp;
queue<int> q;
int vst[MX], seq[MX];
int n, m, v, cnt;
void dfs(int cur) {
  vst[cur] = 1;
  seq[++cnt] = cur;

  for (int i = 0; i < grp[cur].size(); i++) {
    int nxt = grp[cur][i];
    if (vst[nxt] == false) dfs(nxt);
  }
}

void bfs(int cur) {
  vst[cur] = 1;
  seq[++cnt] = cur;
  q.push(cur);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int c : grp[u]) {
      if (vst[c] == 0) {
        vst[c] = 1;
        seq[++cnt] = c;
        q.push(c);
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &v);
  int x, y;
  grp.resize(n + 1);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) sort(grp[i].begin(), grp[i].end());
  dfs(v);
  for (int i = 1; i <= cnt; i++) printf("%d ", seq[i]);
  printf("\n");
  memset(vst, 0, sizeof(vst));
  memset(seq, 0, sizeof(seq));
  cnt = 0;
  bfs(v);
  for (int i = 1; i <= cnt; i++) printf("%d ", seq[i]);
}