#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
constexpr int MC = 1e7 + 1, MX = 4e5 + 1;
constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
vector<pair<int, ll>> vv[MX];
priority_queue<pair<ll, int>> q;
bool pr[MC];
int n, cv[MX];
ll dv[MX];
ll sol() {
  dv[1] = 0;
  q.push({-dv[1], 1});
  while (!q.empty()) {
    ll cw = -q.top().first;
    int cn = q.top().second;
    q.pop();
    if (cw > dv[cn]) continue;
    for (const auto& [an, aw] : vv[cn]) {
      if (pr[cv[cn] + cv[an]] || (dv[an] <= cw + aw)) continue;
      dv[an] = cw + aw;
      q.push({-dv[an], an});
    }
  }
  return dv[n] == INF ? -1LL : dv[n];
}

int main() {
  memset(dv, 0x3f, sizeof dv);
  pr[0] = pr[1] = 1;
  for (int i = 2; i * i < MC; i++) {
    if (pr[i]) continue;
    for (int j = i * i; j < MC; j += i) pr[j] = 1;
  }

  int m, s, e;
  ll w;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &cv[i]);
  while (m--) {
    scanf("%d %d %lld", &s, &e, &w);
    if (pr[cv[s] + cv[e]]) continue;
    vv[s].push_back({e, w});
    vv[e].push_back({s, w});
  }

  ll r = sol();
  if (r == -1LL)
    printf("Now where are you?");
  else
    printf("%lld", r);
}