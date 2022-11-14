#include <iostream>
#include <queue>
#define MX 101
using namespace std;
int n, m, v[MX], u[MX], d[MX];
queue<int> q;
void bfs() {
  v[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int i = 1; i <= 6; i++) {
      int nc = c + i;
      if (nc >= MX) continue;
      if (v[nc] != 0) continue;
      v[nc] = v[c] + 1;
      while (1) {
        if (u[nc] != 0)
          nc = u[nc];
        else if (d[nc] != 0)
          nc = d[nc];
        else
          break;
      }
      if (v[nc] == 0 || (v[c] + 1 < v[nc])) v[nc] = v[c] + 1;
      q.push(nc);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    u[x] = y;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    d[x] = y;
  }
  bfs();
  cout << --v[100];
}