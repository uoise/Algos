#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

constexpr int MX = 1e4 + 1, INF = 0x3f3f3f3f;
std::vector<std::pair<int, int>> v[MX];
std::priority_queue<std::pair<int, int>> pq;
int n, dv[MX];
void sol() {
  int s, e, w, c, d;
  memset(dv, 0x3f, sizeof dv);
  for (int i = 0; i < MX; i++) v[i].clear();
  scanf("%d %d %d", &n, &d, &c);
  while (d--) {
    scanf("%d %d %d", &e, &s, &w);
    v[s].push_back({e, w});
  }

  dv[c] = 0;
  pq.push({-dv[c], c});
  while (!pq.empty()) {
    w = -pq.top().first, s = pq.top().second;
    pq.pop();
    for (const auto& p : v[s]) {
      if (dv[p.first] <= w + p.second) continue;
      dv[p.first] = w + p.second;
      pq.push({-dv[p.first], p.first});
    }
  }

  s = 0, e = 0;
  for (int i = 1; i <= n; i++) {
    if (dv[i] >= INF) continue;
    ++s;
    e = std::max(e, dv[i]);
  }
  printf("%d %d\n", s, e);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}