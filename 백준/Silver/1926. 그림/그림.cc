#include <iostream>
#include <vector>
using namespace std;

int n, m, r, xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};
vector<vector<bool>> g, v;
void bfs(int y, int x) {
  v[y][x] = true;
  r++;
  for (int i = 0; i < 4; i++) {
    const int ny = y + yy[i], nx = x + xx[i];
    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
    if (v[ny][nx] || !g[ny][nx]) continue;
    bfs(ny, nx);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  g.assign(n, vector<bool>(m));
  v.assign(n, vector<bool>(m, false));

  int c;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) {
      cin >> c;
      g[y][x] = c == 1 ? true : false;
    }

  int res = 0, cnt = 0;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (!v[y][x] && g[y][x]) {
        r = 0;
        bfs(y, x);
        if (r > 0) cnt++;
        if (res < r) res = r;
      }

  cout << cnt << '\n' << res;
}