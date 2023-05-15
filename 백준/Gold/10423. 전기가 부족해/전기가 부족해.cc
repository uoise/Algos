#include <algorithm>
#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> q;
int gv[1001];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return false;
  if (x < y) std::swap(x, y);
  gv[x] = y;
  return true;
}

int main() {
  int n, m, k, u, v, c, r = 0;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) gv[i] = i;

  while (k--) {
    scanf("%d", &u);
    gv[u] = 0;
  }

  while (m--) {
    scanf("%d %d %d", &u, &v, &c);
    q.push({c, u, v});
  }

  while (!q.empty()) {
    c = q.top().c, u = q.top().u, v = q.top().v;
    q.pop();
    if (mks(u, v)) r += c;
  }
    
  printf("%d", r);
}