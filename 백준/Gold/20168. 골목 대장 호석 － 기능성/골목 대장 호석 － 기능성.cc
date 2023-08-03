#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

constexpr int MX = 11;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> vv[MX];
vector<int> wv;
int n, a, b, c, dv[MX];
bool sol(const int& lmt) {
  memset(dv, 0x3f, sizeof dv);
  int cur, cst;
  dv[a] = 0;
  pq.push({-dv[a], a});
  while (!pq.empty()) {
    cur = pq.top().second, cst = -pq.top().first;
    pq.pop();
    for (const auto& nxt : vv[cur]) {
      if (nxt.second > lmt) continue;
      if (dv[nxt.first] <= cst + nxt.second) continue;
      dv[nxt.first] = cst + nxt.second;
      pq.push({-dv[nxt.first], nxt.first});
    }
  }

  return dv[b] <= c;
}

int main() {
  int s, e, d, l = 0, r, m, res = -1;
  scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
  while (m--) {
    scanf("%d %d %d", &s, &e, &d);
    vv[s].push_back({e, d});
    vv[e].push_back({s, d});
    wv.push_back(d);
  }

  sort(wv.begin(), wv.end());
  wv.erase(unique(wv.begin(), wv.end()), wv.end());

  r = wv.size() - 1;
  while (l <= r) {
    m = (l + r) / 2;
    if (sol(wv[m]))
      res = wv[m], r = m - 1;
    else
      l = m + 1;
  }

  printf("%d", res);
}