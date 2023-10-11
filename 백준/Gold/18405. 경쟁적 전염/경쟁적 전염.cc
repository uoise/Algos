#include <cstdio>
#include <queue>
#include <vector>

constexpr int MX = 201, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
std::vector<std::pair<int, int>> bv[1001];
std::queue<std::pair<int, std::pair<int, int>>> q;
int n, k, vv[MX][MX];
void sol(const int& t) {
  int y, x, ny, nx, c, d;
  for (int i = 1; i <= k; i++)
    for (const auto& p : bv[i]) q.push({0, p});

  while (!q.empty()) {
    c = q.front().first;
    y = q.front().second.first, x = q.front().second.second;
    q.pop();
    if (c++ >= t) continue;
    for (d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (vv[ny][nx]) continue;
      vv[ny][nx] = vv[y][x];
      q.push({c, {ny, nx}});
    }
  }
}

int main() {
  int s, x, y;
  scanf("%d %d", &n, &k);
  for (y = 0; y < n; y++) {
    for (x = 0; x < n; x++) {
      scanf("%d", &vv[y][x]);
      bv[vv[y][x]].push_back({y, x});
    }
  }
  scanf("%d %d %d", &s, &x, &y);
  sol(s);
  printf("%d", vv[x - 1][y - 1]);
}