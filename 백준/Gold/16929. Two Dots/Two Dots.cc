#include <cstdio>
#include <cstring>
#include <queue>
constexpr int MX = 51, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
char cv[MX][MX];
int n, m, bv[MX][MX];
bool bfs(int y, int x) {
  bv[y][x] = 1;
  q.push({y, x});
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (cv[ny][nx] != cv[y][x]) continue;
      if (bv[y][x] + 1 == bv[ny][nx]) return 1;
      if (bv[ny][nx]) continue;
      bv[ny][nx] = bv[y][x] + 1;
      q.push({ny, nx});
    }
  }
  memset(bv, 0, sizeof bv);
  return 0;
}

bool sol() {
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (!bv[y][x] && bfs(y, x)) return 1;
  return 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) scanf("%s", cv[y]);
  printf("%s", sol() ? "Yes" : "No");
}