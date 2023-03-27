#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 1001, INF = 0x3f3f3f3f;
int n, m, b, e, c;
int vv[MX][MX], dv[MX];
std::priority_queue<std::pair<int, int>> pq;
void sol() {
  while (!pq.empty()) {
    c = -pq.top().first, b = pq.top().second;
    pq.pop();
    for (int i = 1; i <= n; i++) {
      if (vv[b][i] >= INF) continue;
      if (c + vv[b][i] < dv[i]) {
        dv[i] = c + vv[b][i];
        pq.push({-dv[i], i});
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  memset(dv, 0x3f, sizeof dv);
  memset(vv, 0x3f, sizeof vv);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &b, &e, &c);
    if (vv[b][e] > c) vv[b][e] = c;
  }
  scanf("%d %d", &b, &e);
  dv[b] = 0;
  pq.push({-dv[b], b});
  sol();
  printf("%lld", dv[e]);
}