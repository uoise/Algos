#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 101, INF = 0x3f3f3f3f;
std::priority_queue<std::pair<int, int>> pq;
std::priority_queue<int> rq;
bool bv[MX];
int n, vv[MX][MX], gv[MX];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x != y) gv[x] = y;
}

int main() {
  int m, i, s, e, r = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) gv[i] = i;
  memset(vv, 0x3f, sizeof vv);
  while (m--) {
    scanf("%d %d", &s, &e);
    vv[s][e] = vv[e][s] = 1;
    mks(s, e);
  }

  for (i = 1; i <= n; i++)
    for (s = 1; s <= n; s++)
      for (e = s + 1; e <= n; e++)
        if (vv[s][e] > vv[s][i] + vv[i][e])
          vv[s][e] = vv[e][s] = vv[s][i] + vv[i][e];

  for (s = 1; s <= n; s++) {
    m = 0;
    for (e = 1; e <= n; e++) {
      if (e == s) continue;
      if (vv[s][e] >= INF) continue;
      m = m < vv[s][e] ? vv[s][e] : m;
    }
    pq.push({-m, s});
  }

  while (!pq.empty()) {
    s = pq.top().second;
    pq.pop();
    if (bv[fnd(s)]) continue;
    rq.push(-s);
    bv[fnd(s)] = 1;
  }

  printf("%d\n", rq.size());
  while (!rq.empty()) {
    printf("%d\n", -rq.top());
    rq.pop();
  }
}