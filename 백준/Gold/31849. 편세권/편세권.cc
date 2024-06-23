#include <algorithm>
#include <cstdio>
#include <queue>

constexpr int MN = 1001, xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
int n, m, r, c, lv[MN][MN], bv[MN][MN], ret = 0x3f3f3f3f;
int main() {
  scanf("%d %d %d %d", &n, &m, &r, &c);
  while (r--) {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);
    lv[x][y] = t;
  }

  while (c--) {
    int x, y;
    scanf("%d %d", &x, &y);
    bv[x][y] = 1;
    q.push({x, y});
  }

  while (q.size()) {
    auto [x, y] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ax = x + xx[d], ay = y + yy[d];
      if (!ax || ax > n || !ay || ay > m) continue;
      if (bv[ax][ay]) continue;
      bv[ax][ay] = bv[x][y] + 1;
      if (lv[ax][ay]) ret = std::min(ret, lv[ax][ay] * bv[x][y]);
      q.push({ax, ay});
    }
  }

  printf("%d", ret);
}