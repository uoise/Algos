#include <cstdio>
#include <queue>
#include <vector>

constexpr int MX = 1e4 + 1;
std::queue<int> q;
std::vector<std::pair<int, int>> vv[MX], rv[MX];
int n, bv[MX], dv[MX];
int main() {
  int c, m, s, e, w;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %d", &s, &e, &w);
    vv[s].push_back({e, w});
    rv[e].push_back({s, w});
    ++bv[e];
  }

  scanf("%d %d", &s, &e);
  // find length
  q.push(s);
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (const auto& p : vv[c]) {
      dv[p.first] = std::max(dv[p.first], dv[c] + p.second);
      if (!--bv[p.first]) q.push(p.first);
    }
  }

  // find route
  q.push(e);
  bv[e] = 1, s = 0;
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (const auto& p : rv[c]) {
      if (dv[c] != dv[p.first] + p.second) continue;
      ++s;
      if (bv[p.first]) continue;
      bv[p.first] = 1;
      q.push(p.first);
    }
  }

  printf("%d\n%d", dv[e], s);
}