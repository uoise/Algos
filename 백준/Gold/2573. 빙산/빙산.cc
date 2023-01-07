#include <cstdio>
#include <cstring>

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, m, t, vv[300][300], nv[300][300];
bool bv[300][300];
constexpr auto sz = sizeof(bv), cz = sizeof(nv);
void dfs(int y, int x) {
  int cnt = 0;
  bv[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + yy[i], nx = x + xx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (vv[ny][nx]) {
      if (!bv[ny][nx]) dfs(ny, nx);
    } else {
      ++cnt;
    }
  }
  nv[y][x] = ((vv[y][x] <= cnt) ? 0 : (vv[y][x] - cnt));
}

int sol() {
  int ny, nx;
  while (1) {
    int cnt = 0;
    for (int y = 0; y < n; y++)
      for (int x = 0; x < m; x++)
        if (vv[y][x] && !bv[y][x]) dfs(y, x), ++cnt;
    if (cnt != 1) return cnt ? t : 0;
    memcpy(vv, nv, cz);
    memset(bv, 0, sz);
    memset(nv, 0, cz);
    t++;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) scanf("%d", &vv[y][x]);

  printf("%d", sol());
}