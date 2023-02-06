#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

constexpr int MX = 5e4 + 1, DX = 18;
vector<int> v[MX];
int n, m, dv[MX], pv[MX][DX];
void dfs(int cur) {
  for (int i = 1; i < DX; i++) pv[cur][i] = pv[pv[cur][i - 1]][i - 1];
  for (const auto& nxt : v[cur]) {
    if (!dv[nxt]) {
      pv[nxt][0] = cur, dv[nxt] = dv[cur] + 1;
      dfs(nxt);
    }
  }
}

int sol(int x, int y) {
  if (x == 1 || y == 1) return 1;
  if (dv[x] < dv[y]) swap(x, y);

  if (dv[x] > dv[y])
    for (int i = DX - 1; i >= 0; i--)
      if (dv[pv[x][i]] >= dv[y]) x = pv[x][i];
    
  int res = x;
  if (x != y) {
    for (int i = DX - 1; i >= 0; i--) {
      if (pv[x][i] != pv[y][i]) x = pv[x][i], y = pv[y][i];
      res = pv[x][i];
    }
  }
  return res;
}

int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }

  pv[1][0] = 1, dv[1] = 1;
  dfs(1);

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", sol(x, y));
  }
}