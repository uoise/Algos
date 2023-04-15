#include <cstdio>
#include <queue>

constexpr int MX = 501;

std::queue<int> q, sq[MX];
int n, r, rv[MX], tv[MX], vv[MX];
int main() {
  scanf("%d", &n);
  for (int u = 1; u <= n; u++) {
    scanf("%d", &tv[u]);
    int v = 0;
    while (1) {
      scanf("%d", &v);
      if (v == -1) break;
      vv[u]++;
      sq[v].push(u);
    }
  }

  while (1) {
    for (int i = 1; i <= n; i++) {
      if (vv[i]) continue;
      q.push(i);
      vv[i] = -1;
      tv[i] += rv[i];
    }
    if (q.empty()) break;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      while (!sq[u].empty()) {
        int v = sq[u].front();
        rv[v] = std::max(rv[v], tv[u]), --vv[v];
        sq[u].pop();
      }
    }
  }

  for (int u = 1; u <= n; u++) printf("%d\n", tv[u]);
}