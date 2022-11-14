#include <iostream>

using namespace std;

int vv[501][501], n, m, r;
constexpr int yy[][3] = {{1, 2, 3},  {0, 0, 0},  {1, 0, 1},  {1, 2, 1},
                         {0, 0, 1},  {1, 1, 2},  {0, 1, 1},  {0, 1, 2},
                         {0, 0, 1},  {1, 2, 2},  {0, 1, 2},  {0, 0, 1},
                         {1, 1, 1},  {0, 1, 1},  {0, 1, -1}, {1, 1, 1},
                         {-1, 0, 1}, {0, 0, -1}, {1, 2, 2}},
              xx[][3] = {{0, 0, 0}, {1, 2, 3},  {0, 1, 1}, {0, 0, 1},
                         {1, 2, 1}, {0, 1, 1},  {1, 1, 2}, {1, 0, 0},
                         {1, 2, 0}, {0, 0, 1},  {1, 1, 1}, {1, 2, 2},
                         {0, 1, 2}, {1, 0, -1}, {1, 0, 1}, {-1, 0, 1},
                         {1, 1, 1}, {1, 2, 2},  {0, 0, -1}};

void clc(const int y, const int x) {
  int y1, y2, y3, x1, x2, x3, v = vv[y][x];
  for (int i = 0; i < 19; i++) {
    y1 = y + yy[i][0], x1 = x + xx[i][0];
    y2 = y + yy[i][1], x2 = x + xx[i][1];
    y3 = y + yy[i][2], x3 = x + xx[i][2];

    if (y1 >= n || y2 >= n || y3 >= n || x1 >= m || x2 >= m || x3 >= m)
      continue;

    if (i > 12)
      if (y1 < 0 || y2 < 0 || y3 < 0 || x1 < 0 || x2 < 0 || x3 < 0) continue;

    r = max(r, v + vv[y1][x1] + vv[y2][x2] + vv[y3][x3]);
  }
}

void sol() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> vv[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) clc(i, j);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  sol();
  cout << r;
}