#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> q;
int n, gv[100001];
long long r;
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
  int m, c, u, v;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d %d", &u, &v, &c);
    r += c;
    q.push({c, u, v});
  }

  m = n - 1;
  while (!q.empty() && m) {
    if (mks(q.top().u, q.top().v)) r -= q.top().c, --m;
    q.pop();
  }
  int tgt = fnd(1);
  for (int i = 2; i <= n; i++) {
    if (tgt != fnd(i)) {
      r = -1;
      break;
    }
  }
  printf("%lld", r);
}