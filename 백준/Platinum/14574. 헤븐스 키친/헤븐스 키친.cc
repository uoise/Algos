#include <cmath>
#include <cstdio>
#include <queue>

constexpr int MX = 1001;
struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c < o.c; }
};

std::priority_queue<cuv> q;
int n, gv[MX];
bool dv[MX][MX], bv[MX];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  gv[x] = y;
  return 1;
}

void init() {
  scanf("%d", &n);
  int pv[MX], cv[MX];
  for (int i = 1; i <= n; i++) scanf("%d %d", &pv[i], &cv[i]);
  for (int i = 1; i <= n; i++) {
    gv[i] = i;
    for (int j = i + 1; j <= n; j++)
      q.push({(cv[i] + cv[j]) / abs(pv[i] - pv[j]), i, j});
  }
}

void dfs(const int& x) {
  bv[x] = 1;
  for (int i = 1; i <= n; i++) {
    if (bv[i] || !dv[x][i]) continue;
    dfs(i);
    printf("%d %d\n", x, i);
  }
}

int main() {
  init();
  int cnt = n - 1;
  long long res = 0;
  while (cnt && !q.empty()) {
    int c = q.top().c, u = q.top().u, v = q.top().v;
    q.pop();
    if (!mks(u, v)) continue;
    res += c, cnt--;
    dv[u][v] = dv[v][u] = 1;
  }
  printf("%lld\n", res);
  dfs(1);
}