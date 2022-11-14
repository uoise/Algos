#include <iostream>
#include <queue>
#define MX 1001
using namespace std;
int m, n, v[MX][MX], r;
int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int bfs() {
  for (int y = 0; y < m; y++)
    for (int x = 0; x < n; x++)
      if (v[y][x] == 1) q.push({x, y});
  while (!q.empty()) {
    int cx = q.front().first, cy = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cx + xx[i], ny = cy + yy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (v[ny][nx] != 0) continue;
      v[ny][nx] = v[cy][cx] + 1;
      q.push({nx, ny});
    }
  }

  for (int y = 0; y < m; y++)
    for (int x = 0; x < n; x++) {
      if (v[y][x] == 0) return -1;
      if (v[y][x] > r) r = v[y][x];
    }
  return --r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int y = 0; y < m; y++)
    for (int x = 0; x < n; x++) cin >> v[y][x];

  cout << bfs() << '\n';
}