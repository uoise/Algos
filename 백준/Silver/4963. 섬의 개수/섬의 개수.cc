#include <cstdio>

bool vv[50][50];
int xx[] = {1, 0, -1, 0, 1, 1, -1, -1}, yy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int T, w, h, r;

void dfs(int y, int x) {
  vv[y][x] = 0;
  for (int i = 0; i < 8; i++) {
    int ny = y + yy[i], nx = x + xx[i];
    if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
    if (vv[ny][nx]) dfs(ny, nx);
  }
}

int main() {
  while (1) {
    scanf("%d %d", &w, &h);
    if (!w && !h) break;
    r = 0;
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) scanf("%d", &vv[y][x]);

    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        if (vv[y][x]) {
          dfs(y, x);
          r++;
        }

    printf("%d\n", r);
  }
}