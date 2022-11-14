#include <algorithm>
#include <iostream>
using namespace std;
int n, cnt, v[26][26], g[26][26], c[626];

void dfs(int cx, int cy, int cg) {
  v[cy][cx] = cg;
  c[cg]++;

  if ((cy + 1 <= n) && (g[cy + 1][cx] == 1) && (v[cy + 1][cx] == 0))
    dfs(cx, cy + 1, cg);

  if ((cy - 1 >= 1) && (g[cy - 1][cx] == 1) && (v[cy - 1][cx] == 0))
    dfs(cx, cy - 1, cg);

  if ((cx + 1 <= n) && (g[cy][cx + 1] == 1) && (v[cy][cx + 1] == 0))
    dfs(cx + 1, cy, cg);

  if ((cx - 1 >= 1) && (g[cy][cx - 1] == 1) && (v[cy][cx - 1] == 0))
    dfs(cx - 1, cy, cg);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  string inp;
  for (int y = 1; y <= n; y++) {
    cin >> inp;
    for (int x = 0; x < n; x++) g[y][x + 1] = inp[x] - '0';
  }

  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= n; x++)
      if ((g[y][x] == 1) && (v[y][x] == 0)) dfs(x, y, ++cnt);

  sort(c + 1, c + cnt + 1);
  cout << cnt << '\n';
  for (int i = 1; i <= cnt; i++) cout << c[i] << '\n';
}