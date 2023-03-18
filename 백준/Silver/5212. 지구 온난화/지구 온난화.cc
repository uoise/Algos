#include <algorithm>
#include <cstdio>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
char vv[10][11];
int r, c, ny, nx, cnt, ux = -1, uy = -1, dx = 11, dy = 11;
int main() {
  scanf("%d %d", &r, &c);
  for (int y = 0; y < r; y++) scanf("%s", vv[y]);
  for (int y = 0; y < r; y++) {
    for (int x = 0; x < c; x++) {
      if (vv[y][x] != 'X') continue;
      cnt = 0;
      for (int d = 0; d < 4; d++) {
        ny = y + yy[d], nx = x + xx[d];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || vv[ny][nx] == '.') ++cnt;
      }
      if (cnt > 2)
        vv[y][x] = '!';
      else
        ux = max(x, ux), uy = max(y, uy), dx = min(x, dx), dy = min(y, dy);
    }
  }
  for (int y = dy; y <= uy; y++) {
    for (int x = dx; x <= ux; x++)
      printf("%c", vv[y][x] == '!' ? '.' : vv[y][x]);
    printf("\n");
  }
}