#include <cstdio>
#include <vector>

using namespace std;

constexpr int xx[] = {0, -1, 0, 1}, yy[] = {-1, 0, 1, 0};  // n0 w1 s2 e3
int vv[50][50], n, m;

int sol() {
  int cx, cy, d, nx, ny, t, r = 0;
  scanf("%d %d %d", &cy, &cx, &d);
  if (d % 2) d = (d + 2) % 4; // w <-> e
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) scanf("%d", &vv[i][j]);

  do {
    t = 5;
    if (!vv[cy][cx]) vv[cy][cx] = 2, ++r;
    for (int i = (d + 1) % 4; --t; i = ++i % 4) {
      ny = cy + yy[i], nx = cx + xx[i];
      if (!vv[ny][nx]) {
        cy = ny, cx = nx, d = i;
        break;
      }
    }
    if (!t) cy += yy[(d + 2) % 4], cx += xx[(d + 2) % 4];
  } while (vv[cy][cx] != 1);

  return r;
}

int main() {
  scanf("%d %d", &n, &m);
  printf("%d", sol());
}