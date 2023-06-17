#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 101;
constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
int n, m, y, x, ny, nx, vv[MX][MX];
bool bv[MX][MX];
int main() {
  scanf("%d %d", &m, &n);
  memset(vv, 0x3f, sizeof vv);
  vv[0][0] = 0;
  char inp[m];
  for (y = 0; y < n; y++) {
    scanf("%s", inp);
    for (x = 0; x < m; x++) bv[y][x] = (inp[x] == '1');
  }
  q.push({0, 0});
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (vv[ny][nx] <= vv[y][x] + (bv[ny][nx] ? 1 : 0)) continue;
      vv[ny][nx] = vv[y][x] + (bv[ny][nx] ? 1 : 0);
      q.push({ny, nx});
    }
  }
  printf("%d", vv[n - 1][m - 1]);
}