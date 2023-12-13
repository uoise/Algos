#include <algorithm>
#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
struct yx {
  int y, x, f, e;
  bool operator<(const yx& o) const {
    if (f != o.f) return f > o.f;
    if (e != o.e) return e > o.e;
    if (y != o.y) return y < o.y;
    return x < o.x;
  }
};

yx cv[401];
int n, fv[401][4], vv[21][21];
void sol(int c) {
  int s = 0;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (vv[y][x]) continue;
      int f = 0, e = 0;
      for (int d = 0; d < 4; d++) {
        int ny = y + yy[d], nx = x + xx[d];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (!vv[ny][nx]) {
          ++e;
          continue;
        }
        for (int i = 0; i < 4; i++) {
          if (fv[c][i] != vv[ny][nx]) continue;
          ++f;
          break;
        }
      }
      cv[s++] = {y, x, f, e};
    }
  }
  std::sort(cv, cv + s);
  vv[cv[0].y][cv[0].x] = c;
}

int clc(int y, int x) {
  int c = vv[y][x], f = 0, p = 1;
  for (int d = 0; d < 4; d++) {
    int ny = y + yy[d], nx = x + xx[d];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
    for (int i = 0; i < 4; i++) {
      if (fv[c][i] != vv[ny][nx]) continue;
      ++f;
      break;
    }
  }

  if (!f) return 0;
  while (--f) p *= 10;
  return p;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n * n; i++) {
    int c;
    scanf("%d", &c);
    for (int j = 0; j < 4; j++) scanf("%d", &fv[c][j]);
    sol(c);
  }
  int r = 0;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) r += clc(y, x);
  printf("%d", r);
}