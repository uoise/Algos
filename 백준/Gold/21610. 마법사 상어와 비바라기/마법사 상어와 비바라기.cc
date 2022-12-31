#include <cstdio>
#include <queue>

using namespace std;

constexpr int xx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
              yy[8] = {0, -1, -1, -1, 0, 1, 1, 1}, 
              qx[4] = {1, -1, -1, 1},
              qy[4] = {1, 1, -1, -1};
int n, m, d, s, r, vv[50][50], cv[50][50];
queue<pair<int, int>> cq, rq;
void mvc() {
  while (!cq.empty()) {
    int cy = cq.front().first, cx = cq.front().second;
    cq.pop();
    int ny = (cy + yy[d] * s) % n, nx = (cx + xx[d] * s) % n;
    while (ny < 0) ny += n;
    while (nx < 0) nx += n;
    ++vv[ny][nx];
    rq.push({ny, nx});
  }

  while (!rq.empty()) {
    int cy = rq.front().first, cx = rq.front().second;
    rq.pop();
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      int dy = cy + qy[i], dx = cx + qx[i];
      if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;
      if (vv[dy][dx]) ++cnt;
    }
    vv[cy][cx] += cnt;
    cv[cy][cx] = -1;
  }

  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) {
      if (cv[y][x] == -1) {
        cv[y][x] = 0;
      } else if (vv[y][x] > 1) {
        vv[y][x] -= 2;
        cq.push({y, x});
      }
    }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &vv[i][j]);
  cq.push({n - 1, 0});
  cq.push({n - 1, 1});
  cq.push({n - 2, 0});
  cq.push({n - 2, 1});
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &d, &s);
    --d;
    mvc();
  }
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) r += vv[y][x];
  printf("%d", r);
}