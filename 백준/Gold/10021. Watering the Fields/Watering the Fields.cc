#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return v > o.v; }
};

std::priority_queue<cuv> pq;
int n, c, gv[2001], r, lv[2001][2], d;
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

int clc(const int& i, const int& j) {
  int x = lv[i][0] - lv[j][0];
  int y = lv[i][1] - lv[j][1];
  return x * x + y * y;
}

int main() {
  scanf("%d %d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &lv[i][0], &lv[i][1]);
    gv[i] = i;
  }

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if ((d = clc(i, j)) >= c) pq.push({i, j, d});

  --n;
  while (!pq.empty() && n) {
    if (mks(pq.top().c, pq.top().u)) r += pq.top().v, --n;
    pq.pop();
  }

  printf("%d", n ? -1 : r);
}