#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1}, MX = 101;
int a, b, n, vv[MX][MX], dv[MX];
int cti(const char& d) {
  if (d == 'N') return 0;
  if (d == 'E') return 1;
  if (d == 'S') return 2;
  return 3;
}

int main() {
  bool chk = 0;
  int m, r, d, f, y, x;
  char c;
  scanf("%d %d %d %d", &a, &b, &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %c", &x, &y, &c);
    dv[i] = cti(c), vv[y][x] = i;
  }

  while (m--) {
    scanf("%d %c %d", &r, &c, &f);
    if (chk) continue;
    if (c != 'F') {
      dv[r] = (dv[r] + (c == 'L' ? -1 : 1) * (f % 4) + 4) % 4;
      continue;
    }

    for (int Y = 1; Y <= b; Y++)
      for (int X = 1; X <= a; X++)
        if (vv[Y][X] == r) {
          y = Y, x = X;
          vv[y][x] = 0;
          break;
        }

    while (f--) {
      y += yy[dv[r]], x += xx[dv[r]];
      if (!y || y > b || !x || x > a) {
        printf("Robot %d crashes into the wall", r);
        chk = 1;
        break;
      }

      if (vv[y][x]) {
        printf("Robot %d crashes into robot %d", r, vv[y][x]);
        chk = 1;
        break;
      }
    }
    if (f == -1) vv[y][x] = r;
  }
  if (!chk) printf("OK");
}