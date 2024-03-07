#include <cstdio>
#include <queue>

constexpr int MX = 1001, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
int n, m, v[MX][MX], r[MX][MX];
int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      scanf("%d", &v[y][x]);
      if (v[y][x] != 2) continue;
      r[y][x] = 1;
      q.push({y, x});
    }
  }

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ay = y + yy[d], ax = x + xx[d];
      if (ay < 0 || ay >= n || ax < 0 || ax >= m) continue;
      if (!v[ay][ax] || r[ay][ax]) continue;
      r[ay][ax] = r[y][x] + 1;
      q.push({ay, ax});
    }
  }
  
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) printf("%d ", r[y][x] ? r[y][x] - 1 : v[y][x] ? -1 : 0);
    printf("\n");
  }
}