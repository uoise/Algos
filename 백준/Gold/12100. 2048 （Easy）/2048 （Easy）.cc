#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::deque<int> q;
int n, res, vv[20][20];
void stp(int& y, int& x, const int& p, const int& d) {
  y = d % 2 ? (d == 1 ? 0 : n - 1) : p;  // y: p, 0, p, n-1
  x = d % 2 ? p : (d ? n - 1 : 0);       // x: 0, p, n-1, p
}

void mov(const int& p, int d) {
  int y, x, t;
  stp(y, x, p, d);
  for (int i = 0; i < n; i++, y += yy[d], x += xx[d]) {
    t = vv[y][x];
    if (!t) continue;
    vv[y][x] = 0;
    if (!q.empty() && t == q.back()) {
      q.pop_back();
      t *= -2;
    }
    q.push_back(t);
  }

  d = (d + 2) % 4;
  stp(y, x, p, d);
  while (!q.empty()) {
    vv[y][x] = abs(q.front());
    q.pop_front();
    if (res < vv[y][x]) res = vv[y][x];
    y += yy[d], x += xx[d];
  }
}

void dfs(const int T) {
  if (T == 5) return;
  int tv[20][20];
  for (int d = 0; d < 4; d++) {
    memcpy(tv, vv, sizeof vv);
    for (int j = 0; j < n; j++) mov(j, d);
    if (!memcmp(vv, tv, sizeof vv)) continue;
    dfs(T + 1);
    memcpy(vv, tv, sizeof vv);
  }
}

int main() {
  scanf("%d", &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%d", &vv[y][x]);
  res = vv[0][0];
  dfs(0);
  printf("%d", res);
}