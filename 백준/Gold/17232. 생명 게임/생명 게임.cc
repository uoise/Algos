#include <cstdio>
#include <cstring>

int n, m, k, s, t, a, b, sv[101][101];
bool vv[2][101][101], tg;
void inp() {
  scanf("%d %d %d\n%d %d %d", &n, &m, &t, &k, &a, &b);
  s = 2 * k + 1;
  char c, cv[101];
  for (int y = 1; y <= n; y++) {
    scanf("%s", cv);
    for (int x = 0; x < m; x++)
      if (cv[x] == '*') vv[tg][y][x + 1] = 1;
  }
}

void ptv() {
  auto& rv = vv[tg];
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) printf("%c", (rv[y][x] ? '*' : '.'));
    printf("\n");
  }
}

int clc(int y, int x) {
  int ly = y - k, lx = x - k, ry = y + k, rx = x + k;
  ly = ly < 1 ? 1 : ly;
  lx = lx < 1 ? 1 : lx;
  ry = ry > n ? n : ry;
  rx = rx > m ? m : rx;
  return sv[ry][rx] - sv[ry][lx - 1] - sv[ly - 1][rx] + sv[ly - 1][lx - 1];
}

void sol() {
  auto &nv = vv[!tg], &cv = vv[tg];
  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= m; x++)
      sv[y][x] = cv[y][x] + sv[y - 1][x] + sv[y][x - 1] - sv[y - 1][x - 1];

  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= m; x++) {
      int nr = clc(y, x) - cv[y][x];
      if ((cv[y][x] && nr >= a && nr <= b) ||
          ((!cv[y][x] && nr > a && nr <= b)))
        nv[y][x] = 1;
    }
  tg = !tg;
  memset(cv, 0, sizeof cv);
  memset(sv, 0, sizeof sv);
}

int main() {
  inp();
  while (t--) sol();
  ptv();
}