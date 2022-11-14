#include <string.h>

#include <algorithm>
#include <iostream>
using namespace std;
int w, h, k;
bool g[51][51], v[51][51];
void dfs(int cx, int cy) {
  v[cy][cx] = 1;
  if ((cy + 1 < h) && g[cy + 1][cx] && !v[cy + 1][cx]) dfs(cx, cy + 1);
  if ((cy - 1 >= 0) && g[cy - 1][cx] && !v[cy - 1][cx]) dfs(cx, cy - 1);
  if ((cx + 1 < w) && g[cy][cx + 1] && !v[cy][cx + 1]) dfs(cx + 1, cy);
  if ((cx - 1 >= 0) && g[cy][cx - 1] && !v[cy][cx - 1]) dfs(cx - 1, cy);
}

void sol() {
  cin >> w >> h >> k;
  memset(g, 0, sizeof(g));
  memset(v, 0, sizeof(v));
  int x, y, r = 0;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    g[y][x] = 1;
  }

  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (g[y][x] && !v[y][x]) {
        dfs(x, y);
        r++;
      }

  cout << r << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) sol();
}