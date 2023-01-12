#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, sz = 1e2;
int n, m, s, ny, nx, vv[sz][sz];
bool bv[sz][sz];
queue<pair<int, int>> q;
int bfs(int y, int x) {
  int r = 0;
  bv[y][x] = 1;
  q.push({y, x});
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (!bv[ny][nx]) {
        bv[ny][nx] = 1;
        if (vv[ny][nx])
          vv[ny][nx] = 0, ++r;
        else
          q.push({ny, nx});
      }
    }
  }
  return r;
}

int main() {
  int i, r, t = 0;
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) {
      scanf("%d", &i);
      if (y == 0 || y == n - 1 || x == 0 || x == m - 1) continue;
      if (i) vv[y][x] = 1, ++s;
    }

  while (s) {
    memset(bv, 0, sizeof bv);
    r = 0, ++t;
    r += bfs(1, 0);
    s -= r;
  }
  printf("%d\n%d", t, r);
}