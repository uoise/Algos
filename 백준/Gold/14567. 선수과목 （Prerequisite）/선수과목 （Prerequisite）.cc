#include <cstdio>
#include <queue>

constexpr int MX = 1001;

std::queue<int> q, sq[MX];
int n, m, u, v, r, rv[MX], vv[MX];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    vv[v]++;
    sq[u].push(v);
  }

  while (++r) {
    for (int i = 1; i <= n; i++) {
      if (!vv[i]) {
        q.push(i);
        rv[i] = r, vv[i] = -1;
      }
    }
    if (q.empty()) break;
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      while (!sq[c].empty()) {
        vv[sq[c].front()]--;
        sq[c].pop();
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", rv[i]);
}