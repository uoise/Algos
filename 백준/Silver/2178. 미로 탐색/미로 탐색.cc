#include <iostream>
#include <queue>
using namespace std;

int n, m, g[101][101], xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};
bool v[101][101];
queue<pair<int, int>> q;
void bfs() {
  v[1][1] = true;
  q.push({1, 1});
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int cx = u.first + xx[i], cy = u.second + yy[i];
      if (cx < 1 || cx > m || cy < 1 || cy > n) continue;
      if (g[cy][cx] < 1 || v[cy][cx]) continue;
      v[cy][cx] = true;
      g[cy][cx] = g[u.second][u.first] + 1;
      q.push({cx, cy});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  string c;
  for (int y = 1; y <= n; y++) {
    cin >> c;
    for (int x = 1; x <= m; x++) g[y][x] = c[x - 1] - '0';
  }
  bfs();
  cout << g[n][m];
}