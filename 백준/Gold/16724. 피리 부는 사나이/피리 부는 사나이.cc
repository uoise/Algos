#include <cstdio>

constexpr int MX = 1e3 + 1, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

int n, m, vv[MX][MX], bv[MX][MX], r = 1;
void dfs(const int& y, const int& x) {
  const int ny = y + yy[vv[y][x]], nx = x + xx[vv[y][x]];
  if (bv[ny][nx]) {
    if (bv[ny][nx] == r) ++r;
    bv[y][x] = bv[ny][nx];
  } else {
    bv[y][x] = r;
    dfs(ny, nx);
    bv[y][x] = bv[ny][nx];
  }
}

int main() {
  scanf("%d %d", &n, &m);
  char s[MX];
  for (int y = 0; y < n; y++) {
    scanf("%s", s);
    for (int x = 0; x < m; x++)
      vv[y][x] = s[x] == 'D' ? 0 : (s[x] == 'R' ? 1 : (s[x] == 'U' ? 2 : 3));
  }

  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (!bv[y][x]) dfs(y, x);

  printf("%d", r - 1);
}