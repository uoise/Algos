#include <cstdio>
#include <queue>

using namespace std;

int n, m, k, r, xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
bool vv[100][100], bv[100][100];
priority_queue<int> pq;
queue<pair<int, int>> q;
void bfs(int y, int x) {
  int siz = 0;
  ++r;
  bv[y][x] = 1;
  q.push({y, x});
  while (!q.empty()) {
    int cy = q.front().first, cx = q.front().second;
    ++siz;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (!vv[ny][nx] && !bv[ny][nx]) {
        q.push({ny, nx});
        bv[ny][nx] = 1;
      }
    }
  }
  pq.push(-siz);
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int lx, ly, rx, ry;
    scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
    for (int y = ly; y < ry; y++)
      for (int x = lx; x < rx; x++) vv[y][x] = 1;
  }
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (!bv[y][x] && !vv[y][x]) bfs(y, x);
  printf("%d\n", r);
  while (!pq.empty()) {
    printf("%d ", -pq.top());
    pq.pop();
  }
}