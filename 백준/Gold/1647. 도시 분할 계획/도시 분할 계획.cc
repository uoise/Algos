#include <algorithm>
#include <cstdio>
#include <queue>

struct Cuv {
  int c, u, v;
  bool operator<(const Cuv& x) const { return c > x.c; }
};

std::priority_queue<Cuv> pq;
int n, m, r, vv[100001];
int fnd(const int& x) {
  if (x == vv[x]) return x;
  return vv[x] = fnd(vv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  return vv[x] = y;
}

int main() {
  int c, u, v;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &c);
    pq.push({c, (u < v ? u : v), (u < v ? v : u)});
  }

  for (int i = 1; i <= n; i++) vv[i] = i;
  int tgt = n - 1;
  m = 0;
  while (tgt && !pq.empty()) {
    c = pq.top().c, u = pq.top().u, v = pq.top().v;
    pq.pop();
    if (!mks(u, v)) continue;
    r += c;
    m = c > m ? c : m;
  }
  printf("%d", r - m);
}