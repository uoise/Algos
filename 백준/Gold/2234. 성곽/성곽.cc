#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>

constexpr int MX = 51, yy[] = {0, -1, 0, 1}, xx[] = {-1, 0, 1, 0};
std::queue<std::pair<int, int>> q;
std::vector<int> r;
std::set<int> s;
int n, m, v[MX][MX], b[MX][MX];
void bfs(int c, int y, int x) {
  int s = 0;
  q.push({y, x});
  b[y][x] = c;
  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop(), ++s;
    for (int d = 0; d < 4; d++) {
      if (v[cy][cx] & (1 << d)) continue;
      int ay = cy + yy[d], ax = cx + xx[d];
      if (b[ay][ax]) continue;
      b[ay][ax] = c;
      q.push({ay, ax});
    }
  }
  r.push_back(s);
}

int main() {
  scanf("%d %d", &m, &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) scanf("%d", &v[y][x]);

  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (!b[y][x]) bfs(r.size() + 1, y, x);

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      for (int d = 2; d < 4; d++) {
        int ay = y + yy[d], ax = x + xx[d];
        if (ay < n && ax < m && b[y][x] != b[ay][ax]) s.insert(r[b[y][x] - 1] + r[b[ay][ax] - 1]);
      }
    }
  }

  std::sort(r.begin(), r.end());
  printf("%d\n%d\n%d", r.size(), *(--r.end()), *(--s.end()));
}