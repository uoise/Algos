#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> pq, rq;
int n, m, k, gv[1001];
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

int unf(std::priority_queue<cuv>& q) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) gv[i] = i;
  m = n - 1;
  while (!q.empty() && m) {
    if (mks(q.top().u, q.top().v)) q.top().c ? ++cnt : cnt, --m;
    q.pop();
  }
  return cnt;
}

bool sol() {
  while (!pq.empty()) pq.pop();
  while (!rq.empty()) rq.pop();
  char c;
  int u, v;
  while (m--) {
    scanf(" %c %d %d", &c, &u, &v);
    pq.push({c == 'R' ? 0 : 1, u, v});
    rq.push({c == 'R' ? 0 : -1, u, v});
  }

  return unf(pq) <= k && k <= unf(rq);
}

int main() {
  while (1) {
    scanf("%d %d %d", &n, &m, &k);
    if (!(n || m || k)) break;
    printf("%d\n", sol() ? 1 : 0);
  }
}