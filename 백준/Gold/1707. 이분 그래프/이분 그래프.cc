#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MX 20001
using namespace std;

int T, V, E, x, y, cc[MX];
vector<int> vv[MX];

bool bfs(int beg) {
  queue<int> q;
  cc[beg] = 1;
  q.push(beg);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nu : vv[cur]) {
      if (cc[nu] == cc[cur]) return false;
      if (cc[nu] != 0) continue;
      cc[nu] = cc[cur] * -1;
      q.push(nu);
    }
  }
  return true;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
      scanf("%d %d", &x, &y);
      vv[x].push_back(y);
      vv[y].push_back(x);
    }
    
    bool res = true;
    for (int i = 1; i <= V; i++)
      if (cc[i] == 0) {
        res = bfs(i);
        if (!res) break;
      }

    if (res)
      printf("YES\n");
    else
      printf("NO\n");

    for (int i = 1; i <= V; i++) vv[i].clear();
    memset(cc, 0, sizeof(cc));
  }
}
