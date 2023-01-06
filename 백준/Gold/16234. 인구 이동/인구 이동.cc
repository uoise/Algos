#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
pair<int, int> buf[2501];
int vv[50][50], n, l, r, t, sum, cnt;
bool bv[50][50];
constexpr auto sz = sizeof bv;

void dfs(int y, int x) {
  bv[y][x] = 1, sum += vv[y][x], buf[cnt++] = {y, x};
  for (int i = 0; i < 4; i++) {
    int ny = y + yy[i], nx = x + xx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
    if (bv[ny][nx]) continue;
    int df = abs(vv[y][x] - vv[ny][nx]);
    if (df < l || df > r) continue;
    dfs(ny, nx);
  }
}

bool sol() {
  bool res = 0;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      if (!bv[y][x]) {
        cnt = 0, sum = 0;
        dfs(y, x);
        if (cnt > 1) {
          sum /= cnt;
          for (int i = 0; i < cnt; i++) vv[buf[i].first][buf[i].second] = sum;
          res = 1;
        }
      }
  return res;
}

int main() {
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &vv[i][j]);

  while (sol()) {
    ++t;
    memset(bv, 0, sz);
  }
  printf("%d", t);
}