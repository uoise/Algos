#include <algorithm>
#include <cstdio>
#include <queue>

constexpr int MX = 1e6 + 2;

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> q;
bool bv[MX];
long long k;
int n, gv[MX];
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

bool sol() {
  int c, u, v;
  u = fnd(1), c = 0;
  for (int i = 2; !c && i <= n; i++)
    if (u != fnd(i)) c = 1;
  if (!c) return 1;

  while (!q.empty()) {
    c = q.top().c, u = q.top().u, v = q.top().v;
    q.pop();
    if (!mks(u, v)) continue;
    k -= c;
    if (k < 0) return 0;
    u = fnd(1), c = 0;
    for (int i = 2; !c && i <= n; i++)
      if (u != fnd(i)) c = 1;
    if (!c) return 1;
  }

  return 0;
}

int main() {
  int m, c, u, v;
  scanf("%d %d %lld", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c);
    q.push({c, 0, i});
    gv[i] = i;
  }

  while (m--) {
    scanf("%d %d", &u, &v);
    if (u + 1 == v || u - 1 == v)
      bv[std::min(u, v)] = 1;
    else
      bv[n] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (bv[i]) continue;
    if (i == n)
      mks(i, 1);
    else
      mks(i, i + 1);
  }

  printf("%s", sol() ? "YES" : "NO");
}