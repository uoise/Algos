#include <cstdio>
#include <cstring>
#include <queue>
struct cyx {
  int c, y, x;
  bool operator<(const cyx& o) const { return c > o.c; }
};

constexpr int MX = 126;
constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::priority_queue<cyx> q;
int vv[MX][MX], cv[MX][MX], y, x, c, nx, ny, nc;
int sol(const int n) {
  for (y = 0; y < n; y++)
    for (x = 0; x < n; x++) scanf("%d", &vv[y][x]);

  memset(cv, 0x3f, sizeof cv);
  while (!q.empty()) q.pop();

  y = 0, x = 0;
  q.push({cv[y][x] = vv[y][x], y, x});
  while (!q.empty()) {
    c = q.top().c, y = q.top().y, x = q.top().x;
    q.pop();
    for (int d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (cv[ny][nx] <= vv[ny][nx] + c) continue;
      cv[ny][nx] = vv[ny][nx] + c;
      q.push({cv[ny][nx], ny, nx});
    }
  }

  return cv[n - 1][n - 1];
}

int main() {
  int n, o = 0;
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    printf("Problem %d: %d\n", ++o, sol(n));
  }
}