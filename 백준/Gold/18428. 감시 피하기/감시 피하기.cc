#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
char cv[6][6];
int n, r;
bool dfs(int y, int x) {
  int ny, nx;
  for (int d = 0; d < 4; d++) {
    ny = y, nx = x;
    while (1) {
      ny += yy[d], nx += xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
      if (cv[ny][nx] == 'S') return 1;
      if (cv[ny][nx] == 'O') break;
    }
  }
  return 0;
}

void clc() {
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      if (cv[y][x] == 'T' && dfs(y, x)) return;
  r = 1;
}

void btr(int m, int c) {
  if (!c) {
    clc();
    return;
  }
  if (r || m == n * n) return;
  for (int yi = m / n; !r && (yi < n); yi++) {
    for (int xi = (yi == m / n) ? (m % n) : 0; !r && (xi < n); xi++) {
      if (cv[yi][xi] != 'X') continue;
      cv[yi][xi] = 'O';
      btr(yi * xi + 1, c - 1);
      cv[yi][xi] = 'X';
    }
  }
}

int main() {
  scanf("%d\n", &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%c ", &cv[y][x]);
  btr(0, 3);
  printf("%s", r ? "YES" : "NO");
}