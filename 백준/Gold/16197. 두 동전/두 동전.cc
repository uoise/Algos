#include <algorithm>
#include <cstdio>
#include <queue>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

int n, m;
char mv[21][21];
int bv[21][21][21][21];
struct tp {
  int y, x;
  int clc(int d) {
    int ny = y + yy[d], nx = x + xx[d];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) return 1;
    if (mv[ny][nx] == '.') y = ny, x = nx;
    return 0;
  }
  bool operator==(const tp& a) const { return y == a.y && x == a.x; }
};

struct fp {
  tp p1, p2;
  int& fnd() const { return bv[p1.y][p1.x][p2.y][p2.x]; }
};

std::queue<fp> q;
fp c, a;
int sol() {
  c.fnd() = 1;
  q.push(c);
  while (!q.empty()) {
    c = q.front();
    q.pop();
    if(c.fnd() > 10) continue;
    for (int d = 0; d < 4; d++) {
      auto [a1, a2] = c;
      int cnt = a1.clc(d) + a2.clc(d);
      if (cnt == 1) return c.fnd();
      if (cnt == 2 || a1 == a2) continue;
      a = {a1, a2};
      if (a.fnd()) continue;
      a.fnd() = c.fnd() + 1;
      q.push(a);
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  bool chk = 0;
  for (int y = 0; y < n; y++) {
    scanf("%s", mv[y]);
    for (int x = 0; x < m; x++) {
      if (mv[y][x] != 'o') continue;
      if (!chk) c.p1 = {y, x}, chk = 1;
      else c.p2 = {y, x};
      mv[y][x] = '.';
    }
  }
  printf("%d", sol());
}