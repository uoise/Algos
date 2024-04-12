#include <cstdio>
#include <queue>

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, MN = 1001;
struct lc {
  bool b;
  int y, x;
};

std::queue<lc> q;
int n, m, tx, ty, v[2][MN][MN];
int bfs() {
  while (q.size()) {
    const auto [b, y, x] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ay = y + yy[d], ax = x + xx[d];
      if (ay < 0 || ay >= n || ax < 0 || ax >= m || v[b][ay][ax] > 0) continue;
      bool ab = b;
      if (v[b][ay][ax] == -1) {
        if (b)
          ab = 0;
        else
          continue;
      }
      v[ab][ay][ax] = v[b][y][x] + 1;
      if (ay == ty && ax == tx) return v[ab][ay][ax] - 1;
      q.push({ab, ay, ax});
    }
  }
  return -1;
}

int main() {
  scanf("%d %d\n%d %d", &n, &m, &ty, &tx);
  v[1][--ty][--tx] = 1;
  q.push({1, ty, tx});
  scanf("%d %d", &ty, &tx);
  --ty, --tx;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      int t;
      scanf("%d ", &t);
      v[1][y][x] -= t, v[0][y][x] -= t;
    }
  }

  printf("%d", bfs());
}