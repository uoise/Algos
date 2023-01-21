#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct yxt {
  int y, x, t;
};
const int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
queue<yxt> q;
char vv[1000][1001];
yxt c, nt;
int w, h, r, bv[1000][1000], y, x;
bool sol() {
  for (y = 0; y < h; y++)
    for (x = 0; x < w; x++)
      if (vv[y][x] == '*') q.push({y, x, -1});

  for (y = 0; y < h; y++)
    for (x = 0; x < w; x++)
      if (vv[y][x] == '@') q.push({y, x, 1}), vv[y][x] = '.', bv[y][x] = 1;

  while (!q.empty()) {
    c = q.front();
    if (c.t > 0)
      if (!c.y || c.y == h - 1 || !c.x || c.x == w - 1) return r = c.t;
    q.pop();

    for (int i = 0; i < 4; i++) {
      nt = {c.y + yy[i], c.x + xx[i], c.t < 0 ? c.t : c.t + 1};
      if (nt.y < 0 || nt.y >= h || nt.x < 0 || nt.x >= w) continue;
      if (nt.t < 0) {
        if (vv[nt.y][nt.x] == '.') {
          q.push(nt);
          vv[nt.y][nt.x] = '*';
        }
      } else {
        if (bv[nt.y][nt.x]) continue;
        if (vv[nt.y][nt.x] == '.') {
          q.push(nt);
          vv[nt.y][nt.x] = 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &w, &h);
    for (y = 0; y < h; y++) scanf("%s", vv[y]);
    if (sol())
      printf("%d\n", r);
    else
      printf("IMPOSSIBLE\n");
    memset(bv, 0, sizeof bv);
    while (!q.empty()) q.pop();
  }
}