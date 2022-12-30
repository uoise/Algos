#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
using iip = pair<int, int>;
struct yxt {
  int y, x, t;
};

int n, m, d, xx[3] = {-1, 0, 1}, yy[3] = {0, -1, 0};
iip bfs(const vector<vector<int>>& bv, const int y, const int x) {
  queue<yxt> q;
  q.push({y, x, 0});
  while (!q.empty()) {
    int cy = q.front().y, cx = q.front().x, nt = q.front().t + 1;
    q.pop();
    for (int i = 0; i < 3; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (nt > d) continue;
      if (ny < 0 || ny >= y || nx < 0 || nx >= m) continue;
      if (bv[ny][nx]) return {ny, nx};
      q.push({ny, nx, nt});
    }
  }
  return {-1, -1};
}

int sol(vector<vector<int>> bv, int p1, int p2, int p3) {
  queue<iip> buf;
  int cnt = 0;
  for (int tim = n; tim; tim--) {
    buf.push(bfs(bv, tim, p1));
    buf.push(bfs(bv, tim, p2));
    buf.push(bfs(bv, tim, p3));
    while (!buf.empty()) {
      const auto& p = buf.front();
      if ((p.first != -1) && bv[p.first][p.second])
        bv[p.first][p.second] = 0, ++cnt;
      buf.pop();
    }
  }
  return cnt;
}

int main() {
  scanf("%d %d %d", &n, &m, &d);
  vector<vector<int>> bv(n, vector<int>(m));
  for (auto& v : bv)
    for (auto& i : v) scanf("%d", &i);

  int res = 0;
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++)
      for (int k = j + 1; k < m; k++) res = max(res, sol(bv, i, j, k));
  printf("%d", res);
}