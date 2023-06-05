#include <cstdio>
#include <queue>
#define PQ std::priority_queue<int>
#define Q std::queue<int>

constexpr int yy[] = {1, 0, -1, 0, 1, 1, -1, -1},
              xx[] = {0, 1, 0, -1, 1, -1, 1, -1};
PQ pv[11][11];
Q qv[11][11];
int n, vv[11][11], tv[11][11], fv[11][11];
void sts(const int& y, const int& x) {
  PQ& p = pv[y][x];
  Q& q = qv[y][x];
  int& w = vv[y][x];
  int& t = tv[y][x];
  int c, ny, nx;
  while (!p.empty()) {
    c = -p.top();
    p.pop();
    if (w >= c) {
      w -= c;
      q.push(++c);
      if (c % 5) continue;
      for (int d = 0; d < 8; d++) {
        ny = y + yy[d], nx = x + xx[d];
        if (!ny || ny > n || !nx || nx > n) continue;
        qv[ny][nx].push(1);
      }
    } else {
      t += (c / 2);
    }
  }
}

void atw(const int& y, const int& x) {
  PQ& p = pv[y][x];
  Q& q = qv[y][x];
  while (!q.empty()) {
    p.push(-q.front());
    q.pop();
  }

  vv[y][x] += tv[y][x] + fv[y][x];
  tv[y][x] = 0;
}

void sol() {
  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= n; x++) sts(y, x);

  for (int y = 1; y <= n; y++)
    for (int x = 1; x <= n; x++) atw(y, x);
}

int main() {
  int y, x, c, m, k;
  scanf("%d %d %d", &n, &m, &k);

  for (y = 1; y <= n; y++)
    for (x = 1; x <= n; x++) {
      vv[y][x] = 5;
      scanf("%d", &fv[y][x]);
    }

  while (m--) {
    scanf("%d %d %d", &y, &x, &c);
    pv[y][x].push(-c);
  }

  while (k--) sol();
  c = 0;
  for (y = 1; y <= n; y++)
    for (x = 1; x <= n; x++) c += pv[y][x].size();
  printf("%d", c);
}