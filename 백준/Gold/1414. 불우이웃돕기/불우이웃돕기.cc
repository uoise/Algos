#include <cstdio>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

std::priority_queue<cuv> pq;
int n, vv[51][51], gv[51];
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
  char s[51];
  int y, x, w, res = 0, cnt = 0;
  for (y = 0; y < n; y++) gv[y] = y;
  for (y = 0; y < n; y++) {
    scanf("%s", s);
    for (x = 0; x < n; x++) {
      if (s[x] == '0') {
        vv[y][x] = 0;
        continue;
      } else if (s[x] >= 'a') {
        vv[y][x] = s[x] - 'a' + 1;
      } else {
        vv[y][x] = s[x] - 'A' + 27;
      }
      res += vv[y][x];
      if (y != x) pq.push({vv[y][x], y, x});
    }
  }

  while (!pq.empty() && cnt < n) {
    w = pq.top().c, y = pq.top().u, x = pq.top().v;
    pq.pop();
    if (mks(y, x)) ++cnt, res -= w;
  }
  printf("%d", cnt == n - 1 ? res : -1);
}