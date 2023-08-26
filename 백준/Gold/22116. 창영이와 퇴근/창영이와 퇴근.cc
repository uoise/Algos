#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 1001, INF = 0x3f3f3f3f, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

struct yxd {
  int y, x, d;
  bool operator<(const yxd& o) const { return d > o.d; }
};

std::priority_queue<yxd> pq;
int n, a[MX][MX], dv[MX][MX];
int sol() {
  int y, x, w, d, ny, nx, nw;
  dv[0][0] = 0;
  pq.push({0, 0, dv[0][0]});
  while (!pq.empty()) {
    y = pq.top().y, x = pq.top().x, w = pq.top().d;
    pq.pop();
    for (d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      nw = std::max(w, std::abs(a[y][x] - a[ny][nx]));
      if (dv[ny][nx] <= nw) continue;
      pq.push({ny, nx, nw});
      dv[ny][nx] = nw;
    }
  }

  return dv[n - 1][n - 1];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  memset(dv, 0x3f, sizeof dv);
  printf("%d", sol());
}