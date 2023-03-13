#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct yxdv {
  int y, x, d, v;
  bool operator<(const yxdv& a) const { return v > a.v; }
};

constexpr int yy[] = {0, 1, 0, -1}, xx[] = {1, 0, -1, 0};
int w, h, cy, cx, cd, cv, ny, nx, nv, r = 2e9;
char vv[100][101];
int bv[100][100];
priority_queue<yxdv> q;
bool init() {
  memset(bv, 0x3F, sizeof bv);
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (vv[y][x] == 'C') {
        bv[y][x] = -1;
        for (int d = 0; d < 4; d++) {
          ny = y + yy[d], nx = x + xx[d];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w || vv[ny][nx] == '*')
            continue;
          if (vv[ny][nx] == 'C') return 1;
          bv[ny][nx] = 0;
          q.push({ny, nx, d, bv[ny][nx]});
        }
        return 0;
      }
  return 0;
}

int sol() {
  while (!q.empty()) {
    cy = q.top().y, cx = q.top().x, cd = q.top().d, cv = q.top().v;
    q.pop();
    for (int d = 0; d < 4; d++) {
      if (d == ((cd + 2) % 4)) continue;
      ny = cy + yy[d], nx = cx + xx[d], nv = (d == cd ? cv : cv + 1);
      if (ny < 0 || ny >= h || nx < 0 || nx >= w || vv[ny][nx] == '*' ||
          bv[ny][nx] == -1)
        continue;

      if (vv[ny][nx] == 'C') {
        r = r > nv ? nv : r;
        continue;
      }

      if (nv == 1 || bv[ny][nx] > nv) {
        bv[ny][nx] = nv;
        q.push({ny, nx, d, nv});
      }
    }
  }
  return r;
}

int main() {
  scanf("%d %d", &w, &h);
  for (int y = 0; y < h; y++) scanf("%s", vv[y]);
  printf("%d", init() ? 0 : sol());
}