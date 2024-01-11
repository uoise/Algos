#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

constexpr int MX = 5001;
priority_queue<pair<int, int>> q;
vector<pair<int, int>> vv[MX];
int n, dv[MX];
int sol(int c, int e) {
  int w, nw;
  memset(dv, 0x3f, sizeof dv);
  dv[c] = 0;
  q.push({-dv[c], c});
  while (!q.empty()) {
    c = q.top().second, w = -q.top().first;
    q.pop();
    for (const auto& [a, aw] : vv[c]) {
      if (dv[a] <= w + aw) continue;
      dv[a] = w + aw;
      q.push({-dv[a], a});
    }
  }
  return dv[e];
}

int main() {
  int m, s, e, w, t;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %d", &s, &e, &w);
    vv[s].push_back({e, w});
    vv[e].push_back({s, w});
  }
  scanf("%d %d", &s, &t);
  printf("%d", sol(s, t));
}