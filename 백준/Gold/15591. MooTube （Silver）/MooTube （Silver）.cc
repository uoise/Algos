#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

constexpr int MX = 5001, INF = 0x3f3f3f3f;

std::priority_queue<std::pair<int, int>> q;
std::vector<std::pair<int, int>> vv[MX];
int n, dv[MX][MX];
void bfs(const int s) {
  int c = s, w, t;
  q.push({dv[c][c] = INF, c});
  while (!q.empty()) {
    c = q.top().second, w = q.top().first;
    q.pop();
    for (const auto& p : vv[c]) {
      t = std::min(w, p.second);
      if (t <= dv[s][p.first]) continue;
      dv[s][p.first] = t;
      q.push({t, p.first});
    }
  }
  dv[s][s] = 0;
}

int main() {
  int q, s, e, r;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &s, &e, &r);
    vv[s].push_back({e, r});
    vv[e].push_back({s, r});
  }

  for (int i = 1; i <= n; i++) bfs(i);

  while (q--) {
    scanf("%d %d", &s, &e);
    r = 0;
    for (int i = 1; i <= n; i++)
      if (dv[e][i] >= s) ++r;
    printf("%d\n", r);
  }
}