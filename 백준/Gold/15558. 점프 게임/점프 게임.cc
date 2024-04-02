#include <cstdio>
#include <queue>

constexpr int MN = 1e5 + 1, xx[] = {0, 0, 1, -1}, yy[] = {1, -1, 0, 0};

struct lc {
  int x, y, t;
};

std::queue<lc> q;
bool v[2][MN], b[2][MN];
int n, k;
int bfs() {
  q.push({0, 0, 0});
  b[0][0] = 1;
  while (q.size()) {
    auto [x, y, t] = q.front();
    q.pop();
    if (t >= n) break;
    for (int i = 0; i < 4; i++) {
      int ny = y + yy[i] + (i > 1 ? k : 0), nx = x + xx[i];
      if (ny >= n) return 1;
      if (nx < 0 || ny <= t || nx > 1 || ny >= n) continue;
      if (!v[nx][ny] || b[nx][ny]) continue;
      b[nx][ny] = 1;
      q.push({nx, ny, t + 1});
    }
  }

  return 0;
}

int main(void) {
  scanf("%d %d", &n, &k);
  char inp[MN];
  for (int i = 0; i < 2; i++) {
    scanf("%s", inp);
    for (int j = 0; j < n; j++) v[i][j] = inp[j] - '0';
  }
  printf("%d", bfs());
}