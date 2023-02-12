#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, cy, cx, ny, nx, mn, mx;
int v[100][100];
bool bv[100][100], chk;
queue<pair<int, int>> q;
bool bfs(int b, int e) {
  while (!q.empty()) q.pop();
  memset(bv, 0, sizeof bv);
  q.push({0, 0});
  bv[0][0] = 1;
  while (!q.empty()) {
    cy = q.front().first, cx = q.front().second;
    q.pop();
    if (cy == n - 1 && cx == n - 1) return 1;
    for (int i = 0; i < 4; i++) {
      ny = cy + yy[i], nx = cx + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (bv[ny][nx]) continue;
      bv[ny][nx] = 1;
      if (v[ny][nx] < b || v[ny][nx] > e) continue;
      q.push({ny, nx});
    }
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &v[i][j]);
      mn = min(mn, v[i][j]);
      mx = max(mx, v[i][j]);
    }

  int m, l = abs(v[0][0] - v[n - 1][n - 1]), r = mx - mn, res = 2e9;
  while (l <= r) {
    m = (l + r) / 2;
    chk = 0;
    for (int i = mn; i + m <= mx; i++) {
      if (v[0][0] < i || v[0][0] > i + m) continue;
      if (v[n - 1][n - 1] < i || v[n - 1][n - 1] > i + m) continue;
      if (bfs(i, i + m)) {
        res = min(res, m);
        r = m - 1;
        chk = 1;
        break;
      }
    }
    if (!chk) l = m + 1;
  }
  printf("%d", res);
}