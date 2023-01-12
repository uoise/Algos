#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct yxc {
  int y, x, c;
  bool operator<(const yxc& a) const { return c < a.c; }
};

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, sz = 1e2;
int n, ny, nx, nc = 1, ns, cnt, vv[sz][sz], r = 1e9;
bool bv[sz][sz];
yxc pv[sz * sz];
queue<yxc> q;
void dfs(int y, int x) {
  int nr = 0;
  bv[y][x] = 1, vv[y][x] = nc;
  for (int i = 0; i < 4; i++) {
    int ny = y + yy[i], nx = x + xx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
    if (!vv[ny][nx])
      ++nr;
    else if (!bv[ny][nx])
      dfs(ny, nx);
  }
  if (nr) pv[cnt++] = {y, x, nc};
}

int bfs(int y, int x, const int c) {
  while (!q.empty()) q.pop();
  memset(bv, 0, sizeof bv);
  bv[y][x] = 1;
  q.push({y, x, 0});
  while (!q.empty()) {
    y = q.front().y, x = q.front().x, ns = q.front().c;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (bv[ny][nx]) continue;
      bv[ny][nx] = 1, nc = vv[ny][nx];
      if (nc && (c != nc)) return ns;
      q.push({ny, nx, ns + 1});
    }
  }
  return 1e9;
}

int main() {
  scanf("%d", &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%d", &vv[y][x]);

  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      if (vv[y][x] == 1) {
        ++nc;
        dfs(y, x);
      }

  for (int i = 0; i < cnt; i++) r = min(r, bfs(pv[i].y, pv[i].x, pv[i].c));
  printf("%d\n", r);
}