#include <algorithm>
#include <cstdio>
#include <queue>

std::queue<std::pair<int, int>> q;
int n, m, k, l, v[101][101];
bool b[101][101];
bool sol() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) scanf("%d", &v[y][x]);
  scanf("%d", &k);
  l = v[0][0], b[0][0] = 1;
  q.push({0, 0});
  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for (int ay = 0; ay < n; ay++) {
      for (int ax = 0; ax < m; ax++) {
        if (std::abs(y - ay) + std::abs(x - ax) > k) continue;
        if (b[ay][ax] || v[ay][ax] != l) continue;
        if (ay == n - 1 && ax == m - 1) return 1;
        b[ay][ax] = 1;
        q.push({ay, ax});
      }
    }
  }
  return 0;
}

int main() { printf("%s", sol() ? "ALIVE" : "DEAD"); }