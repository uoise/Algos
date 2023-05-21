#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> q;
int n, r, v, gv[301];
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
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) gv[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v);
    q.push({v, 0, i});
  }

  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      scanf("%d", &v);
      if (y == x) continue;
      q.push({v, y, x});
    }
  }
  v = n;
  while (!q.empty() && n) {
    if (mks(q.top().u, q.top().v)) r += q.top().c, --v;
    q.pop();
  }
  printf("%d", r);
}