#include <cstdio>
#include <queue>

constexpr int MX = 1e6 + 1;

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return v < o.v; }
};

std::priority_queue<cuv> pq;
int n, gv[MX], r;
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return false;
  gv[x] = y;
  return true;
}

int main() {
  int m, a, b, c, d;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (d) {
      mks(a, b);
    } else {
      pq.push({a, b, c});
      r += c;
    }
  }

  while (!pq.empty()) {
    a = pq.top().c, b = pq.top().u, c = pq.top().v;
    pq.pop();
    if (mks(a, b)) r -= c;
  }

  printf("%d", r);
}