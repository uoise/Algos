#include <cstdio>
char vv[21][21];
int yy[] = {0, 1, 0, -1}, xx[] = {1, 0, -1, 0}, bv[26], r, c, res;

void dfs(int y, int x, int d) {
  ++bv[vv[y][x] - 'A'];
  if (res < d) res = d;
  for (int i = 0; i < 4; i++) {
    int ny = y + yy[i], nx = x + xx[i];
    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
    if (!bv[vv[ny][nx] - 'A']) dfs(ny, nx, d + 1);
  }
  --bv[vv[y][x] - 'A'];
}

int main() {
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) scanf("%s", vv[i]);
  dfs(0, 0, 1);
  printf("%d", res);
}