#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

constexpr int MX = 1e5 + 1;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
std::priority_queue<std::pair<long long, int>> q;
std::vector<std::pair<int, long long>> vv[MX];
int n;
bool v[MX];
long long dv[MX];
long long sol() {
  int cur = 0, nxt;
  long long cst = 0, nst;
  dv[cur] = cst;
  q.push({-dv[cur], cur});
  while (!q.empty()) {
    cur = q.top().second, cst = -q.top().first;
    q.pop();
    if (cst > dv[cur]) continue;
    for (const auto& p : vv[cur]) {
      nxt = p.first, nst = cst + p.second;
      if (dv[nxt] <= nst) continue;
      dv[nxt] = nst;
      q.push({-nst, nxt});
    }
  }
  return dv[n - 1] == INF ? -1 : dv[n - 1];
}

int main() {
  int m, s, e;
  long long t;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  v[n - 1] = 0;
  memset(dv, 0x3f, sizeof dv);
  while (m--) {
    scanf("%d %d %lld", &s, &e, &t);
    if (v[s] || v[e]) continue;
    vv[s].push_back({e, t});
    vv[e].push_back({s, t});
  }
  printf("%lld", sol());
}