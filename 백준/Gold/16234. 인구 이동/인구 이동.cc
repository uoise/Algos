#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, l, r, t = 1, vv[50][50], bv[50][50];
queue<pair<int, int>> q, bq;
bool bfs(int y, int x) {
  int sum = vv[y][x];
  bv[y][x] = t;
  q.push({y, x});
  bq.push({y, x});
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (bv[ny][nx] >= t) continue;
      int dif = abs(vv[y][x] - vv[ny][nx]);
      if (dif < l || dif > r) continue;
      bv[ny][nx] = t, sum += vv[ny][nx];
      bq.push({ny, nx});
      q.push({ny, nx});
    }
  }

  if (bq.size() == 1) {
    bq.pop();
    return 0;
  }
  
  sum /= bq.size();
  while (!bq.empty()) {
    vv[bq.front().first][bq.front().second] = sum;
    bq.pop();
  }
  return 1;
}

bool sol() {
  int res = 0;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      if (bv[y][x] < t)
        if (bfs(y, x)) ++res;
  return res ? 1 : 0;
}

int main() {
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &vv[i][j]);
  while (sol()) ++t;
  printf("%d", t - 1);
}