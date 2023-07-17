#include <algorithm>
#include <cstdio>

constexpr int MX = 501, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
int n, r, vv[MX][MX], dv[MX][MX];
bool vld(const int& x, const int& y) { return !(y < 0 || y >= n || x < 0 || x >= n); }
int dfs(const int y, const int x) {
  if (dv[y][x] != 1) return dv[y][x];
  for (int d = 0; d < 4; d++) {
    int ny = y + yy[d], nx = x + xx[d];
    if (!vld(ny, nx) || vv[y][x] >= vv[ny][nx]) continue;
    dv[y][x] = std::max(dv[y][x], dfs(ny, nx) + 1);
  }

  return dv[y][x];
}

int main() {
  scanf("%d", &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) {
      scanf("%d", &vv[y][x]);
      dv[y][x] = 1;
    }

  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) r = std::max(r, dfs(y, x));

  printf("%d", r);
}