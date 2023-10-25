#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c < o.c; }
};

std::priority_queue<cuv> q;
int gv[1001];
int fnd(int x) {
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
  int p, w, c, v, s, e, t, r = 0;
  scanf("%d %d %d %d", &p, &w, &c, &v);
  for (int i = 0; i < p; i++) gv[i] = i;
  while (w--) {
    scanf("%d %d %d", &s, &e, &t);
    q.push({t, s, e});
  }

  while (!q.empty() && (fnd(c) != fnd(v))) {
    s = q.top().u, e = q.top().v, t = q.top().c;
    q.pop();
    if (mks(s, e)) r = t;
  }

  printf("%d", r);
}