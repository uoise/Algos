#include <algorithm>
#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

bool bv[51][51];
char vv[51][51];
int n, m, wv[51][51];
int dfs(int y, int x) {
  if (vv[y][x] == 'H') return 0;
  if (bv[y][x]) return -1;
  if (wv[y][x]) return wv[y][x];
  const int& w = vv[y][x] - '0';
  bv[y][x] = 1;
  int r = 0, t;
  for (int i = 0; i < 4; i++) {
    int ny = y + w * yy[i], nx = x + w * xx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    t = dfs(ny, nx);
    if (t == -1) return -1;
    r = std::max(r, t), bv[ny][nx] = 0;
  }
  return wv[y][x] += r + 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) scanf("%s", vv[y]);
  printf("%d", dfs(0, 0));
}