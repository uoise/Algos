#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

constexpr int MN = 1e5 + 1, INF = 0x3f3f3f3f;
struct br {
  int u, d, t;
};

std::priority_queue<std::pair<int, int>> q;
std::vector<br> bv[MN];
int n, m, dv[MN];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, d, t;
    scanf("%d %d %d %d", &u, &v, &d, &t);
    bv[u].push_back({v, d, t}), bv[v].push_back({u, d, t});
  }
  memset(dv, 0xff, sizeof dv);
  dv[n] = INF;
  q.push({dv[n], n});
  while (q.size()) {
    auto [w, c] = q.top();
    q.pop();
    if (dv[c] > w) continue;
    for (const auto& [a, d, t] : bv[c]) {
      int at = std::min(w - d, t - d);
      if (dv[a] >= at) continue;
      dv[a] = at;
      q.push({dv[a], a});
    }
  }
  printf("%d", dv[1]);
}