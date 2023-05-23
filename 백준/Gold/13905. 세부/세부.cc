#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c < o.c; }
};

std::priority_queue<cuv> q;
int n, m, s, e, gv[100001];
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
  int c, u, v, r = 1e7;
  scanf("%d %d %d %d", &n, &m, &s, &e);
  for (int i = 0; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d %d", &u, &v, &c);
    q.push({c, u, v});
  }

  while (!q.empty() && (fnd(s) != fnd(e))) {
    if (mks(q.top().u, q.top().v)) r = q.top().c;
    q.pop();
  }

  printf("%d", (fnd(s) == fnd(e)) ? r : 0);
}