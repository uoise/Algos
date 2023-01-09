#include <cstdio>
#include <queue>

using namespace std;

struct yxt {
  int y, x, t;
};
constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int r, c;
char vv[50][51];
bool bv[50][50];
int bfs() {
  queue<yxt> q;
  int cy, cx, ct;
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      if (vv[y][x] == '*')
        q.push({y, x, -1});
      else if (vv[y][x] == 'S')
        cy = y, cx = x, vv[y][x] = '.';
  q.push({cy, cx, 1});
  while (!q.empty()) {
    cy = q.front().y, cx = q.front().x, ct = q.front().t;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (cy < 0 || cy >= r || cx < 0 || cx >= c) continue;
      if (ct > 0 && !bv[ny][nx]) {
        if (vv[ny][nx] == 'D') {
          return ct;
        } else if (vv[ny][nx] == '.') {
          bv[ny][nx] = 1;
          q.push({ny, nx, ct + 1});
        }
      } else if (ct < 0 && vv[ny][nx] == '.') {
        vv[ny][nx] = '*';
        bv[ny][nx] = 1;
        q.push({ny, nx, ct});
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d %d", &r, &c);
  for (int y = 0; y < r; y++) scanf("%s", &vv[y]);
  int r = bfs();
  if (r)
    printf("%d", r);
  else
    printf("KAKTUS");
}