#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 1001;

std::queue<int> q, sq[MX];
int T, n, m, u, v, r, tv[MX], rv[MX], vv[MX];
void init() {
  r = 0;
  memset(tv, 0, sizeof tv);
  memset(rv, 0, sizeof rv);
  memset(vv, 0, sizeof vv);
  while (!q.empty()) q.pop();
  for (auto& it : sq)
    while (!it.empty()) it.pop();
}

int sol() {
  init();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &tv[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    vv[v]++;
    sq[u].push(v);
  }
  scanf("%d", &r);

  while (vv[r] > 0) {
    for (int i = 1; i <= n; i++) {
      if (vv[i]) continue;
      q.push(i);
      vv[i] = -1;
      tv[i] += rv[i];
    }

    if (vv[r] < 0) break;

    while (!q.empty()) {
      u = q.front();
      q.pop();
      while (!sq[u].empty()) {
        v = sq[u].front();
        rv[v] = std::max(rv[v], tv[u]), --vv[v];
        sq[u].pop();
      }
    }
  }
  return tv[r] + rv[r];
}

int main() {
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}