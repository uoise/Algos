#include <cstdio>
#include <queue>

constexpr int MX = 1001, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

struct yxw {
  int y, x, w;
};

std::queue<yxw> q;
int n, m, k, vv[MX][MX][11];
int sol() {
  int y, x, w, ny, nx, nw;
  vv[0][0][0] = 1;
  q.push({0, 0, 0});
  while (!q.empty()) {
    y = q.front().y, x = q.front().x, w = q.front().w;
    q.pop();
    if ((y == n - 1) && (x == m - 1)) return vv[y][x][w];
    for (int d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d], nw = w;
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (vv[ny][nx][w] != -1 && vv[ny][nx][w]) continue;
      if (vv[ny][nx][w] == -1) nw = w + 1;
      if (nw > k) continue;
      if (vv[ny][nx][nw] != -1 && vv[ny][nx][nw]) continue;
      vv[ny][nx][nw] = vv[y][x][w] + 1;
      q.push({ny, nx, nw});
    }
  }

  return -1;
}

int main() {
  char s[MX];
  int t;
  scanf("%d %d %d", &n, &m, &k);
  for (int y = 0; y < n; y++) {
    scanf("%s", s);
    for (int x = 0; x < m; x++) {
      t = s[x] == '1' ? -1 : 0;
      for (int d = 0; d <= k; d++) vv[y][x][d] = t;
    }
  }
  printf("%d\n", sol());
}