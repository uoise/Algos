#include <algorithm>
#include <cstdio>
#include <queue>

constexpr int MX = 10001;
struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> q;
int n, m, c, u, v, r = MX, cv[MX], gv[MX];
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

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &cv[i]);
    r = std::min(r, cv[i]), gv[i] = i;
  }

  while (m--) {
    scanf("%d %d %d", &u, &v, &c);
    q.push({c * 2 + cv[u] + cv[v], u, v});
  }

  m = n - 1;
  while (m && !q.empty()) {
    if (mks(q.top().u, q.top().v)) r += q.top().c, --m;
    q.pop();
  }

  printf("%d", r);
}