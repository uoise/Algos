#include <cstdio>
#include <queue>

using namespace std;
constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
struct yx {
  int y, x;
  yx operator+(int n) const { return {y + yy[n], x + xx[n]}; }
  void operator+=(int n) { y += yy[n], x += xx[n]; }
  void operator-=(int n) { y -= yy[n], x -= xx[n]; }
  bool operator==(const yx& n) const { return (y == n.y) && (x == n.x); }
};

struct ppd {
  yx r, b;
  int d;
};

char vv[10][11];
int sol(yx rr, yx bb) {
  queue<ppd> q;
  int dep = 0;
  yx nf, nl;
  q.push({rr, bb, dep});
  while (!q.empty()) {
    rr = q.front().r, bb = q.front().b, dep = q.front().d;
    q.pop();
    if (dep >= 10) continue;
    for (int i = 0; i < 4; i++) {
      bool ord = (rr.y * yy[i] + rr.x * xx[i]) > (bb.y * yy[i] + bb.x * xx[i]);
      nf = (ord ? rr : bb), nl = (ord ? bb : rr);

      while (vv[nf.y][nf.x] == '.') nf += i;
      if (vv[nf.y][nf.x] == '#') nf -= i;

      while (vv[nl.y][nl.x] == '.') nl += i;
      if (vv[nl.y][nl.x] == '#') nl -= i;

      if (nf == nl) nl -= i;
      
      const yx &nr = (ord ? nf : nl), &nb = (ord ? nl : nf);
      if (vv[nb.y][nb.x] == 'O') continue;
      if (vv[nr.y][nr.x] == 'O') {
        if (nr == nb + i) continue;
        return dep + 1;
      }
      if ((rr == nr) && (bb == nb)) continue;

      q.push({nr, nb, dep + 1});
    }
  }
  return -1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", vv[i]);
  yx rr, bb;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (vv[i][j] == 'R') rr = {i, j}, vv[i][j] = '.';
      if (vv[i][j] == 'B') bb = {i, j}, vv[i][j] = '.';
    }
  }
  printf("%d", sol(rr, bb));
}