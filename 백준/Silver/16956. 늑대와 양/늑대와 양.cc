#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
int r, c, ny, nx;
char vv[500][501];
bool chk;
bool vld(const int& y, const int& x) {
  for (int d = 0; d < 4; d++) {
    ny = y + yy[d], nx = x + xx[d];
    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
    if (vv[ny][nx] == 'S') return 1;
  }
  return 0;
}

bool sol() {
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      if (vv[y][x] == 'W' && vld(y, x)) return 0;
  return chk = 1;
}

int main() {
  scanf("%d %d", &r, &c);
  for (int y = 0; y < r; y++) scanf("%s", vv[y]);
  printf("%d\n", sol());
  if (chk) {
    for (int y = 0; y < r; y++) {
      for (int x = 0; x < c; x++)
        printf("%c", vv[y][x] == '.' ? 'D' : vv[y][x]);
      printf("\n");
    }
  }
}