#include <iostream>
#include <queue>
#define MX 101
using namespace std;
struct xyz {
  int x, y, z;
  xyz(int x, int y, int z) : x(x), y(y), z(z) {}
};

int xs, ys, zs, r, v[MX][MX][MX];
int xx[6] = {1, -1, 0, 0, 0, 0}, yy[6] = {0, 0, 1, -1, 0, 0},
    zz[6] = {0, 0, 0, 0, 1, -1};
queue<xyz> q;

int bfs() {
  for (int zi = 1; zi <= zs; zi++)
    for (int yi = 1; yi <= ys; yi++)
      for (int xi = 1; xi <= xs; xi++)
        if (v[zi][yi][xi] == 1) q.push(xyz(xi, yi, zi));
  while (!q.empty()) {
    int cx = q.front().x, cy = q.front().y, cz = q.front().z;
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nx = cx + xx[i], ny = cy + yy[i], nz = cz + zz[i];
      if (nx < 1 || nx > xs || ny < 1 || ny > ys || nz < 1 || nz > zs) continue;
      if (v[nz][ny][nx] != 0) continue;
      v[nz][ny][nx] = v[cz][cy][cx] + 1;
      q.push(xyz(nx, ny, nz));
    }
  }
  for (int zi = 1; zi <= zs; zi++)
    for (int yi = 1; yi <= ys; yi++)
      for (int xi = 1; xi <= xs; xi++) {
        if (v[zi][yi][xi] == 0) return -1;
        if (v[zi][yi][xi] > r) r = v[zi][yi][xi];
      }

  return --r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> xs >> ys >> zs;

  for (int zi = 1; zi <= zs; zi++)
    for (int yi = 1; yi <= ys; yi++)
      for (int xi = 1; xi <= xs; xi++) cin >> v[zi][yi][xi];
  cout << bfs() << '\n';
}