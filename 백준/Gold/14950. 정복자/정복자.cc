#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> q;
int n, m, t, r, gv[10001];
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
  int c, u, v;
  scanf("%d %d %d", &n, &m, &t);
  for (int i = 0; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d %d", &u, &v, &c);
    q.push({c, u, v});
  }

  while (!q.empty() && m < n) {
    if (mks(q.top().u, q.top().v)) r += q.top().c + (++m) * t;
    q.pop();
  }

  printf("%d", r);
}