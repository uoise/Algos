#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

std::queue<std::pair<int, int>> q;
bool vv[51][51];
int n, rv[51], bv[51];
int bfs(const int& c) {
  int r = 0, p, d;
  memset(bv, 0, sizeof bv);
  q.push({c, bv[c] = 1});
  while (!q.empty()) {
    p = q.front().first, d = q.front().second;
    q.pop();
    for (int i = 1; i <= n; i++)
      if (!bv[i] && vv[p][i]) q.push({i, bv[i] = bv[p] + 1});
  }
  for (int i = 1; i <= n; i++) r = std::max(r, bv[i]);
  return r - 1;
}

int main() {
  scanf("%d", &n);
  memset(rv, 0x3f, sizeof rv);
  int s, e;
  while (1) {
    scanf("%d %d", &s, &e);
    if (s == -1 && e == -1) break;
    vv[s][e] = vv[e][s] = 1;
  }

  for (int i = 1; i <= n; i++) rv[i] = bfs(i);
  int mx = n * 3, r = 0;
  for (int i = 1; i <= n; i++) mx = std::min(mx, rv[i]);
  for (int i = 1; i <= n; i++) if (rv[i] == mx) ++r;
  printf("%d %d\n", mx, r);
  for (int i = 1; i <= n; i++) if (rv[i] == mx) printf("%d ", i);
}