#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
queue<int> q;
int n, res, tgt, vv[20][20];
int gmx() {
  int r = -1;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) r = max(r, vv[y][x]);
  return r;
}

pair<int, int> stp(const int& p, const int& d) {
  return {d % 2 ? (d == 1 ? 0 : n - 1) : p,  // y: p, 0, p, n-1
          d % 2 ? p : (d ? n - 1 : 0)};      // x: 0, p, n-1, p
}

void psh(int y, int x, const int& d) {
  int l = n;
  while (l--) {
    if (vv[y][x]) q.push(vv[y][x]), vv[y][x] = 0;
    y += yy[d], x += xx[d];
  }
}

void mov(int y, int x, const int& d) {
  while (q.size()) {
    const int t = q.front();
    q.pop();
    if (!vv[y][x]) {
      vv[y][x] = t;
    } else if (vv[y][x] == t) {
      vv[y][x] <<= 1;
      y += yy[d], x += xx[d];
    } else {
      y += yy[d], x += xx[d];
      vv[y][x] = t;
    }
  }
}

void btr(const int T) {
  if (T == 10) {
    res = max(res, gmx());
    return;
  }

  if (gmx() * (1 << 10 - T) <= res) return;
  int tv[20][20];
  memcpy(tv, vv, sizeof vv);
  for (int d = 0; d < 4; d++) {
    for (int j = 0; j < n; j++) {
      const auto [y, x] = stp(j, d);
      psh(y, x, d);
      mov(y, x, d);
    }

    if (!memcmp(vv, tv, sizeof vv)) continue;
    btr(T + 1);
    memcpy(vv, tv, sizeof tv);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> vv[y][x];
      res = max(res, vv[y][x]);
    }
  }
  btr(0);
  cout << res;
}