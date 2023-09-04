#include <cstdio>
#include <queue>

constexpr int MX = 1001, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

struct yxw {
  int y, x, w, c;
  bool g;
};

int n, m, k, v[MX][MX][11];
int sol() {
  std::queue<yxw> q;
  int y, x, w, ny, nx, nw, d, c;
  bool g;
  v[0][0][0] = 1;
  q.push({0, 0, 0, 1, 0});
  while (!q.empty()) {
    y = q.front().y, x = q.front().x, w = q.front().w;
    c = q.front().c, g = q.front().g;
    q.pop();
    if (y == n - 1 && x == m - 1) return c;
    for (d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d], nw = w;
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (v[ny][nx][nw] == 1) continue;
      if (v[ny][nx][nw] == -1) {
        if (c & 1)
          ++nw;
        else
          continue;
      }
      if (nw > k) continue;
      v[ny][nx][nw] = 1;
      q.push({ny, nx, nw, c + 1, 0});
    }
    if (!g) q.push({y, x, w, c + 1, 1});
  }

  return -1;
}

int main() {
  char c[MX];
  scanf("%d %d %d", &n, &m, &k);
  for (int y = 0; y < n; y++) {
    scanf("%s", c);
    for (int x = 0; x < m; x++)
      for (int d = 0; d <= k; d++) v[y][x][d] = c[x] == '0' ? 0 : -1;
  }

  printf("%d", sol());
}