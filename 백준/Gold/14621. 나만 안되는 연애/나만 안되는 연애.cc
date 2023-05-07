#include <iostream>
#include <queue>

using namespace std;

struct cyx {
  int c, y, x;
  bool operator<(const cyx& o) const { return c > o.c; }
};

constexpr int MX = 1001;
priority_queue<cyx> pq;
int n, m, r, gv[MX];
bool bv[MX];
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char g;
    cin >> g;
    if (g == 'M') bv[i] = 1;
    gv[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    if (bv[u] ^ bv[v]) pq.push({d, u, v});
  }
  m = 0;
  while (!pq.empty() && m < n) {
    if (mks(pq.top().x, pq.top().y)) r += pq.top().c, ++m;
    pq.pop();
  }
  const int tgt = fnd(1);
  for (int i = 2; i <= n; i++)
    if (tgt != fnd(i)) r = -1;
  cout << r;
}