#include <algorithm>
#include <cstdio>

using namespace std;

constexpr int yy[] = {1, 0, -1, 0, 1, 1, -1, -1},
              xx[] = {0, 1, 0, -1, 1, -1, 1, -1}, MX = 501, INF = 4e5;

int n, m, v[MX][MX], r[MX][MX];
pair<int, int> g[MX][MX];
pair<int, int> sol(int y, int x) {
  if (g[y][x].first != -1) return g[y][x];
  int ty = y, tx = x, tv = v[y][x];
  for (int d = 0; d < 8; d++) {
    int ay = y + yy[d], ax = x + xx[d];
    if (ay < 0 || ay >= n || ax < 0 || ax >= m) continue;
    if (v[ay][ax] < tv) ty = ay, tx = ax, tv = v[ay][ax];
  }

  return g[y][x] = (ty == y && tx == x) ? make_pair(y, x) : sol(ty, tx);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      scanf("%d", &v[y][x]);
      g[y][x] = {-1, -1};
    }
  }

  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++) ++r[sol(y, x).first][sol(y, x).second];

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) printf("%d ", r[y][x]);
    printf("\n");
  }
}