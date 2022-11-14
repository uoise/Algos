#include <string.h>

#include <iostream>
#include <queue>
#define MX 301
using namespace std;
int T, I, sx, sy, gx, gy, v[MX][MX];
int xx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, yy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs() {
  queue<pair<int, int>> q;
  v[sy][sx] = 1;
  q.push({sx, sy});
  while (!q.empty()) {
    int cx = q.front().first, cy = q.front().second;
    if (gx == cx && gy == cy) break;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = cx + xx[i], ny = cy + yy[i];
      if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
      if (v[ny][nx] != 0) continue;
      v[ny][nx] = v[cy][cx] + 1;
      q.push({nx, ny});
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  while (T--) {
    memset(v, 0, sizeof(v));
    cin >> I >> sx >> sy >> gx >> gy;
    bfs();
    cout << --v[gy][gx] << '\n';
  }
}