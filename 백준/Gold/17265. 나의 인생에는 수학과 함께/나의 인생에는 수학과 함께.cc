#include <cstdio>

constexpr int yy[] = {1, 2, 0, 1}, xx[] = {1, 0, 2, 1}, MX = 0x3f3f3f3f;
char vv[6][6];
int n, h = -MX, l = MX;
void dfs(int c, int y, int x) {
  if (y == n - 1 && x == n - 1) {
    h = c > h ? c : h, l = c < l ? c : l;
    return;
  }

  for (int d = 0; d < 4; d++) {
    int ny = y + yy[d], nx = x + xx[d];
    if (ny > n || nx > n) continue;
    char o = !d       ? vv[y + 1][x]
             : d != 3 ? vv[y + yy[d] / 2][x + xx[d] / 2]
                      : vv[y][x + 1];
    int a = vv[ny][nx] - '0';
    if (o == '+') dfs(c + a, ny, nx);
    if (o == '-') dfs(c - a, ny, nx);
    if (o == '*') dfs(c * a, ny, nx);
  }
}

int main() {
  scanf("%d\n", &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%c ", &vv[y][x]);
  dfs(vv[0][0] - '0', 0, 0);
  printf("%d %d", h, l);
}