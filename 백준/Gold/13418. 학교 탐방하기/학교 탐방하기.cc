#include <algorithm>
#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> pq, rq;
int n, ent, gv[1001];
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

int sol(std::priority_queue<cuv>& q) {
  int c, u, v, r = ent;
  for (int i = 0; i <= n; i++) gv[i] = i;
  mks(0, 1);
  while (!q.empty()) {
    c = q.top().c, u = q.top().u, v = q.top().v;
    q.pop();
    if (mks(u, v) && c) r++;
  }
  return r * r;
}

int main() {
  int m, u, v, c;
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &u, &v, &c);
  ent = c ? 0 : 1;
  while (m--) {
    scanf("%d %d %d", &u, &v, &c);
    c = c ? 0 : 1;
    pq.push({c, u, v});
    rq.push({-c, u, v});
  }

  printf("%d", sol(rq) - sol(pq));
}