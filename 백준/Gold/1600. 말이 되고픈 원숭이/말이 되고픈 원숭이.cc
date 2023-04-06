#include <cstdio>
#include <queue>

struct Cp {
  int d, y, x, t;
};

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, MX = 200;
constexpr int hx[] = {1, 2, 2, 1, -1, -2, -2, -1};
constexpr int hy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int k, w, h, mv[MX][MX][31], ny, nx;
bool vv[MX][MX];
std::queue<Cp> q;

int sol() {
  Cp c = {0, 0, 0, mv[0][0][0] = 1};
  q.push(c);
  while (!q.empty()) {
    c = q.front();
    if (c.y == h - 1 && c.x == w - 1) return c.t - 1;
    ++c.t;
    q.pop();
    for (int d = 0; d < 4; d++) {
      ny = c.y + yy[d], nx = c.x + xx[d];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w || vv[ny][nx] ||
          mv[ny][nx][c.d])
        continue;
      q.push({c.d, ny, nx, mv[ny][nx][c.d] = c.t});
    }
    if (++c.d > k) continue;
    for (int d = 0; d < 8; d++) {
      ny = c.y + hy[d], nx = c.x + hx[d];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w || vv[ny][nx] ||
          mv[ny][nx][c.d])
        continue;
      q.push({c.d, ny, nx, mv[ny][nx][c.d] = c.t});
    }
  }
  return -1;
}

int main() {
  scanf("%d %d %d", &k, &w, &h);
  int p;
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      scanf("%d", &p);
      vv[y][x] = p;
    }
  printf("%d", sol());
}