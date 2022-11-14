#include <iostream>
#include <queue>
#define MX 1001
using namespace std;
struct xyb {
  int x, y;
  bool b;
  xyb(int x, int y, bool b = false) : x(x), y(y), b(b) {}
};
int xs, ys, v[MX][MX], b[MX][MX];
int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};
queue<xyb> q;

int bfs() {
  v[1][1] = 1;
  b[1][1] = 1;
  q.push(xyb(1, 1));
  while (!q.empty()) {
    int cx = q.front().x, cy = q.front().y;
    bool cb = q.front().b;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cx + xx[i], ny = cy + yy[i];
      bool nb = cb;
      if (nx < 1 || nx > xs || ny < 1 || ny > ys) continue;
      if (v[ny][nx] == -1) {
        if (cb || b[ny][nx] > 0) continue;
        b[ny][nx] = v[cy][cx] + 1;
        nb = true;
      } else {
        if (cb) {
          if (b[ny][nx] != 0) continue;
          b[ny][nx] = b[cy][cx] + 1;
        } else {
          if (v[ny][nx] != 0) continue;
          v[ny][nx] = v[cy][cx] + 1;
        }
      }

      q.push(xyb(nx, ny, nb));
    }
  }
  if (v[ys][xs] == 0 && b[ys][xs] == 0) return -1;
  if (v[ys][xs] == 0 || b[ys][xs] == 0)
    return v[ys][xs] > b[ys][xs] ? v[ys][xs] : b[ys][xs];
  return v[ys][xs] < b[ys][xs] ? v[ys][xs] : b[ys][xs];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> ys >> xs;
  string ts;
  for (int y = 1; y <= ys; y++) {
    cin >> ts;
    for (int x = 0; x < xs; x++) v[y][x + 1] = (ts[x] - '0' == 1) ? -1 : 0;
  }
  cout << bfs();
}