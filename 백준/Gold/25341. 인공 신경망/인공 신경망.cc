#include <cstdio>
#include <queue>

constexpr int MX = 2222;
std::queue<std::pair<int, int>> qv[MX];
int tv[MX];
long long bv[MX], ev[MX], mv[MX], s, r;
int main() {
  int n, m, q, c, w;
  scanf("%d %d %d", &n, &m, &q);
  for (int d = 0; d < m; d++) {
    scanf("%d", &c);
    for (int i = 0; i < c; i++) scanf("%d", &tv[i]);
    for (int i = 0; i < c; i++) {
      scanf("%d", &w);
      qv[tv[i] - 1].push({w, d});
    }
    scanf("%lld", &bv[d]);
  }

  for (int i = 0; i < m; i++) {
    scanf("%lld", &ev[i]);
    s += ev[i] * bv[i];
  }
  scanf("%d", &w);
  s += w;

  for (int i = 0; i < n; i++) {
    while (!qv[i].empty()) {
      mv[i] += ev[qv[i].front().second] * qv[i].front().first;
      qv[i].pop();
    }
  }
  
  while (q--) {
    r = s;
    for (int i = 0; i < n; i++) {
      scanf("%d", &w);
      r += mv[i] * w;
    }
    printf("%lld\n", r);
  }
}