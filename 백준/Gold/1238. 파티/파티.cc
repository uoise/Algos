#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
using iip = pair<int, int>;
using vip = vector<iip>;
constexpr int INF = 2e9;
vector<vip> vv, rv;
vector<int> dv, dr;
int n, m, x;
void djs(const vector<vip>& grp, vector<int>& dst) {
  priority_queue<iip> pq;
  dst[x] = 0;
  pq.push({-dst[x], x});
  while (!pq.empty()) {
    int cur = pq.top().second, cst = -pq.top().first;
    pq.pop();
    for (const auto& nxt : grp[cur]) {
      if (dst[nxt.first] > nxt.second + cst) {
        dst[nxt.first] = nxt.second + cst;
        pq.push({-dst[nxt.first], nxt.first});
      }
    }
  }
}

int sol() {
  djs(vv, dv);
  djs(rv, dr);
  int res = -1;
  for (int i = 1; i <= n; i++)
    if (res < dv[i] + dr[i]) res = dv[i] + dr[i];
  return res;
}

int main() {
  scanf("%d %d %d", &n, &m, &x);
  vv.assign(n + 1, vip());
  rv.assign(n + 1, vip());
  dv.assign(n + 1, INF);
  dr.assign(n + 1, INF);
  for (int i = 0; i < m; i++) {
    int u, v, t;
    scanf("%d %d %d", &u, &v, &t);
    vv[u].push_back({v, t});
    rv[v].push_back({u, t});
  }
  printf("%d", sol());
}