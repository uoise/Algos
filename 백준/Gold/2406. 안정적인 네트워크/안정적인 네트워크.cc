#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

constexpr int MX = 1001;
std::priority_queue<cuv> pq;
std::queue<std::pair<int, int>> q;
int n, m, s, e, r, gv[MX];
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

bool vld() {
  const int t = fnd(2);
  for (int i = 3; i <= n; i++)
    if (t != fnd(i)) return 0;
  return 1;
}

void sol() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d", &s, &e);
    mks(s, e);
  }

  if (n == 1) {
    printf("0 0");
    return;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &m);
      if (i == 1 || j == 1 || i <= j) continue;
      pq.push({m, i, j});
    }

  while (!vld() && !pq.empty()) {
    m = pq.top().c, s = pq.top().u, e = pq.top().v;
    pq.pop();
    if (!mks(s, e)) continue;
    r += m;
    q.push({s, e});
  }

  printf("%d %d\n", r, q.size());
  while (!q.empty()) {
    printf("%d %d\n", q.front().first, q.front().second);
    q.pop();
  }
}

int main() { sol(); }