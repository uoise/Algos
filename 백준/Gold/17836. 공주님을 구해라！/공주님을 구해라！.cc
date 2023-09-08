#include <algorithm>
#include <cstdio>
#include <queue>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1}, INF = 1e4 + 2;

std::queue<std::pair<int, int>> q;
int n, m, t, r, vv[101][101];
int sol() {
  int y, x, d, ny, nx, sr = INF;
  q.push({1, 1});
  vv[1][1] = 1;
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    if (vv[y][x] > std::min(t, sr)) continue;
    if (y == n && x == m) return std::min(vv[y][x] - 1, sr);
    for (d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (!ny || ny > n || !nx || nx > m) continue;
      if (vv[ny][nx] == -2) {
        vv[ny][nx] = vv[y][x] + 1;
        sr = (vv[ny][nx] - 1) + (n - ny) + (m - nx);
      }
      if (vv[ny][nx]) continue;
      q.push({ny, nx});
      vv[ny][nx] = vv[y][x] + 1;
    }
  }

  return sr;
}

int main() {
  scanf("%d %d %d", &n, &m, &t);
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      scanf("%d", &vv[y][x]);
      vv[y][x] *= -1;
    }
  }

  if ((r = sol()) > t) printf("Fail");
  else printf("%d", r);
}