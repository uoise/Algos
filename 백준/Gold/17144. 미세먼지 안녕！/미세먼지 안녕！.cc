#include <cstdio>
#include <cstring>

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int r, c, t, vv[50][50], tv[50][50], cd, cu, ny, nx;
void clc(int y, int x) {
  int ri = vv[y][x] / 5;
  for (int d = 0; d < 4; d++) {
    ny = y + yy[d], nx = x + xx[d];
    if (ny < 0 || ny >= r || nx < 0 || nx >= c || vv[ny][nx] < 0) continue;
    vv[y][x] -= ri, tv[ny][nx] += ri;
  }
  tv[y][x] += vv[y][x];
}

void mva() {
  tv[cu][0] = tv[cd][0] = 0;
  int y = cu + yy[3], x = xx[3];
  ny = y, nx = x;  // 3 0 1 2 -> (d+3)%4
  for (int d = 0; d < 4; d++) {
    while (1) {
      ny += yy[(d + 3) % 4], nx += xx[(d + 3) % 4];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c || ny > cu) {
        ny -= yy[(d + 3) % 4], nx -= xx[(d + 3) % 4];
        break;
      }

      tv[y][x] = tv[ny][nx];
      y = ny, x = nx;
      if (vv[ny][nx] < 0) break;
    }
  }

  y = cd + yy[1], x = xx[1];
  ny = y, nx = x;  // 1 0 3 2 -> (d+2)%4
  for (int d = 3; d >= 0; d--) {
    while (1) {
      ny += yy[(d + 2) % 4], nx += xx[(d + 2) % 4];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c || ny < cd) {
        ny -= yy[(d + 2) % 4], nx -= xx[(d + 2) % 4];
        break;
      }

      tv[y][x] = tv[ny][nx];
      y = ny, x = nx;
      if (vv[ny][nx] < 0) break;
    }
  }

  tv[cu][0] = tv[cd][0] = -1;
  memcpy(vv, tv, sizeof tv);
  memset(tv, 0, sizeof tv);
}

int main() {
  scanf("%d %d %d", &r, &c, &t);
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++) {
      scanf("%d", &vv[y][x]);
      if (vv[y][x] == -1) {
        if (!cu)
          cu = y;
        else
          cd = y;
      }
    }

  while (t--) {
    for (int y = 0; y < r; y++)
      for (int x = 0; x < c; x++)
        if (vv[y][x] > 0) clc(y, x);
    mva();
  }

  int res = 0;
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++) res += vv[y][x] > 0 ? vv[y][x] : 0;
  printf("%d", res);
}