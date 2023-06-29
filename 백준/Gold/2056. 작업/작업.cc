#include <cstdio>
#include <queue>

constexpr int MX = 1e4 + 1;
std::queue<int> q[MX], c;
int n, r, vv[MX], wv[MX], rv[MX];
int main() {
  scanf("%d", &n);
  int m, x;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &wv[i], &m);
    while (m--) {
      scanf("%d", &x);
      ++vv[i];
      q[x].push(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (vv[i]) continue;
    c.push(i);
    rv[i] = wv[i];
  }

  while (!c.empty()) {
    m = c.front();
    c.pop();

    while (!q[m].empty()) {
      x = q[m].front();
      q[m].pop();
      if (!--vv[x]) c.push(x);
      rv[x] = std::max(rv[x], rv[m] + wv[x]);
    }
  }

  for (int i = 1; i <= n; i++) r = std::max(r, rv[i]);
  printf("%d", r);
}