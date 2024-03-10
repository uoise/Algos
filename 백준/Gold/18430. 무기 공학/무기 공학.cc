#include <algorithm>
#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
int n, m, v[5][5], r;
bool b[5][5];
bool vld(int y, int x) { return y >= 0 && y < n && x >= 0 && x < m && !b[y][x]; }
void btr(int y, int x, int s) {
  if (y == n) return;
  int ny = (y * m + x + 1) / m, nx = (y * m + x + 1) % m;
  btr(ny, nx, s);
  for (int d = 0; d < 4; d++) {
    int ly = y + yy[d], lx = x + xx[d];
    int ry = y + yy[(d + 1) % 4], rx = x + xx[(d + 1) % 4];
    if (!vld(y, x) || !vld(ly, lx) || !vld(ry, rx)) continue;
    int t = v[y][x] * 2 + v[ly][lx] + v[ry][rx];
    b[y][x] = b[ly][lx] = b[ry][rx] = 1, r = std::max(r, s + t);
    btr(ny, nx, s + t);
    b[y][x] = b[ly][lx] = b[ry][rx] = 0;
  }
}

int sol() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) scanf("%d", &v[y][x]);
  if (n < 2 || m < 2) return 0;
  btr(0, 0, 0);
  return r;
}

int main() { printf("%d", sol()); }