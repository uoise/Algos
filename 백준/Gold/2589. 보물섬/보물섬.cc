#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct yxt {
  int y, x, t;
};

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, m, ny, nx, t, r = -1, bv[50][50];
char vv[50][51];
queue<yxt> q;
void sol(int y, int x) {
  bv[y][x] = 0;
  q.push({y, x, bv[y][x]});
  while (!q.empty()) {
    y = q.front().y, x = q.front().x, t = q.front().t;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (vv[ny][nx] == 'L' && bv[ny][nx] < 0)
        q.push({ny, nx, bv[ny][nx] = t + 1});
    }
  }
  if (r < t) r = t;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) scanf("%s", vv[y]);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (vv[y][x] == 'L') {
        memset(bv, 0xFF, sizeof bv);
        sol(y, x);
      }
  printf("%d", r);
}