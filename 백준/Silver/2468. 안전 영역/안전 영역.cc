#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, d, r, vv[100][100];
bool bv[100][100];
const auto siz = sizeof bv;
void bfs(int y, int x) {
  q.push({y, x});
  bv[y][x] = 1;
  while (!q.empty()) {
    int cy = q.front().first, cx = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (bv[ny][nx] || vv[ny][nx] <= d) continue;
      bv[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &vv[i][j]);
      d = max(d, vv[i][j]);
    }

  while (d--) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (!bv[i][j] && (vv[i][j] > d)) {
          bfs(i, j);
          ++cnt;
        }
    r = max(r, cnt);
    memset(bv, 0, siz);
  }
  printf("%d", r);
}