#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1}, MX = 101;
vector<pair<int, int>> sv[MX][MX];
queue<pair<int, int>> q;
int n, bv[MX][MX], r;
bool vld(int y, int x) {
  if (bv[y][x] != 1) return 0;
  int ny, nx;
  for (int d = 0; d < 4; d++) {
    ny = y + yy[d], nx = x + xx[d];
    if (!ny || ny > n || !nx || nx > n) continue;
    if (bv[ny][nx] == 2) return 1;
  }
  return 0;
}

int sol() {
  bv[1][1] = 1;
  q.push({1, 1});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    if (bv[y][x] != 1) continue;
    bv[y][x] = 2;
    for (const auto& [ay, ax] : sv[y][x]) {
      bv[ay][ax] = max(1, bv[ay][ax]);
      if (vld(ay, ax)) q.push({ay, ax});
    }
    for (int d = 0; d < 4; d++) {
      int ny = y + yy[d], nx = x + xx[d];
      if (!ny || ny > n || !nx || nx > n) continue;
      if (bv[ny][nx] != 1) continue;
      bv[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= n; x++)
      if (bv[y][x]) ++r;
  return r;
}

int main() {
  int m, x, y, a, b;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    sv[y][x].push_back({b, a});
  }
  printf("%d", sol());
}