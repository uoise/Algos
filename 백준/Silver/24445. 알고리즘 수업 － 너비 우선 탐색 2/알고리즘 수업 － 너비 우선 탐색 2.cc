#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MX 100001
using namespace std;

int n, m, r, cnt;
vector<int> vst, seq;
vector<vector<int>> grp;
queue<int> q;
void bfs() {
  vst[r] = 1;
  seq[r] = ++cnt;
  q.push(r);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int c : grp[u]) {
      if (vst[c] == 0) {
        vst[c] = 1;
        seq[c] = ++cnt;
        q.push(c);
      }
    }
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &r);
  vst.resize(n + 1);
  seq.resize(n + 1);
  grp.resize(n + 1);
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    sort(grp[i].begin(), grp[i].end(), greater<int>());
  bfs();
  for (int i = 1; i <= n; i++) printf("%d\n", seq[i]);
}