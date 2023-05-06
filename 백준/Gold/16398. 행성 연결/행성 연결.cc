#include <cstdio>
#include <queue>
struct cyx {
  int c, y, x;
  bool operator<(const cyx& o) const { return c > o.c; }
};

constexpr int MX = 1001;
std::priority_queue<cyx> pq;
int n, c, gv[MX];
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
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) gv[i] = i;
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      scanf("%d", &c);
      if (y < x) pq.push({c, y, x});
    }
  }
  c = 0;
  while (!pq.empty() && c < n) {
    if (mks(pq.top().x, pq.top().y)) r += pq.top().c, ++c;
    pq.pop();
  }
  printf("%lld", r);
}