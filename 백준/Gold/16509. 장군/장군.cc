#include <cstdio>
#include <queue>

constexpr int xx[8][3] = {{1, 2, 3},    {0, 1, 2},   {0, -1, -2}, {-1, -2, -3},
                          {-1, -2, -3}, {0, -1, -2}, {0, 1, 2},   {1, 2, 3}};
constexpr int yy[8][3] = {{0, 1, 2},   {1, 2, 3},    {1, 2, 3},    {0, 1, 2},
                          {0, -1, -2}, {-1, -2, -3}, {-1, -2, -3}, {0, -1, -2}};

std::queue<std::pair<int, int>> q;
int vv[10][9], ty, tx;
int chk(const int& y, const int& x) {
  if (y == ty && x == tx) return 1;
  if (y < 0 || y > 9 || x < 0 || x > 8) return -1;
  return 0;
}

void dgo(const int& y, const int& x, const int& d) {
  int ny, nx, nc = vv[y][x] + 1, st;
  for (int g = 0; g < 3; g++) {
    ny = y + yy[d][g], nx = x + xx[d][g];
    st = chk(ny, nx);
    if (st < 0 || (st > 0 && g < 2)) return;
  }
  vv[ny][nx] = nc;
  if (st == 0) q.push({ny, nx});
}

int sol() {
  int y, x;
  while (vv[ty][tx] < 0 && !q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 8; d++) dgo(y, x, d);
  }

  return vv[ty][tx] > 0 ? vv[ty][tx] - 1 : -1;
}

int main() {
  int y, x;
  scanf("%d %d %d %d", &y, &x, &ty, &tx);
  vv[ty][tx] = -1, vv[y][x] = 1;
  q.push({y, x});
  printf("%d\n", sol());
}