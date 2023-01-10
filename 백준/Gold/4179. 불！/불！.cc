#include <cstdio>
#include <queue>

using namespace std;
struct yxt {
  int y, x, t;
};

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, sz = 1e3;
int r, c;
char vv[sz][sz + 1];
bool bv[sz][sz];
int bfs() {
  queue<yxt> q;
  int cy, cx, ct;
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      if (vv[y][x] == 'F') q.push({y, x, -1});

  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      if (vv[y][x] == 'J') {
        if (y == 0 || y == r - 1 || x == 0 || x == c - 1) return 1;
        vv[y][x] = '.';
        q.push({y, x, 1});
      }

  while (!q.empty()) {
    cy = q.front().y, cx = q.front().x, ct = q.front().t;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (cy < 0 || cy >= r || cx < 0 || cx >= c) continue;
      if (ct > 0 && !bv[ny][nx] && vv[ny][nx] == '.') {
        if (ny == 0 || ny == r - 1 || nx == 0 || nx == c - 1) return ct + 1;
        bv[ny][nx] = 1;
        q.push({ny, nx, ct + 1});
      } else if (ct < 0 && vv[ny][nx] == '.') {
        vv[ny][nx] = 'F';
        bv[ny][nx] = 1;
        q.push({ny, nx, ct});
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d %d", &r, &c);
  for (int y = 0; y < r; y++) scanf("%s", vv[y]);
  int r = bfs();
  if (r)
    printf("%d", r);
  else
    printf("IMPOSSIBLE");
}