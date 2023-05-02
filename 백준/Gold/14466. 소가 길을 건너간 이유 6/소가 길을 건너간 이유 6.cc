#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 101;
constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
bool bv[MX][MX], rv[MX][MX][4];
int n, k, r, res, by, ey, bx, ex, ty, tx, vv[MX];
bool bfs(const int& b, const int& e) {
  memset(bv, 0, sizeof bv);
  while (!q.empty()) q.pop();
  by = vv[b] / MX, bx = vv[b] % MX;
  ey = vv[e] / MX, ex = vv[e] % MX;
  q.push({by, bx});
  bv[by][bx] = 1;
  while (!q.empty()) {
    by = q.front().first, bx = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      if (rv[by][bx][d]) continue;
      ty = by + yy[d], tx = bx + xx[d];
      if (ty < 1 || ty > n || tx < 1 || tx > n || bv[ty][tx]) continue;
      if (ty == ey && tx == ex) return 1;
      bv[ty][tx] = 1;
      q.push({ty, tx});
    }
  }
  return 0;
}

int main() {
  scanf("%d %d %d", &n, &k, &r);
  for (int i = 0; i < r; i++) {
    scanf("%d %d %d %d", &by, &bx, &ey, &ex);
    ty = by - ey, tx = bx - ex;
    int d = ty ? (ty > 0 ? 1 : 3) : (tx > 0 ? 0 : 2);
    rv[by][bx][(d + 2) % 4] = 1;
    rv[ey][ex][d] = 1;
  }

  for (int i = 0; i < k; i++) {
    scanf("%d %d", &by, &bx);
    vv[i] = by * MX + bx;
  }

  for (int i = 0; i < k; i++)
    for (int j = i + 1; j < k; j++)
      if (!bfs(i, j)) ++res;
  printf("%d", res);
}