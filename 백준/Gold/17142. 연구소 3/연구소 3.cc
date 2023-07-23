#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 51, INF = 1e9, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
std::pair<int, int> pv[MX * MX];
int n, m, y, x, ny, nx, r = INF, o, cnt, vv[MX][MX], tv[MX][MX];
bool bv[MX * MX], iv[MX][MX];
int clc() {
  memcpy(tv, vv, sizeof vv);

  for (int i = 0; i < cnt; i++) {
    if (!bv[i]) continue;
    q.push(pv[i]);
    tv[pv[i].first][pv[i].second] = 1;
  }

  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || tv[ny][nx]) continue;
      tv[ny][nx] = tv[y][x] + 1;
      q.push({ny, nx});
    }
  }

  int ret = 1;
  for (y = 0; y < n; y++) {
    for (x = 0; x < n; x++) {
      if (iv[y][x]) continue;
      if (!tv[y][x]) return INF;
      ret = std::max(ret, tv[y][x]);
    }
  }

  return ret;
}

int sol(const int dep, const int pos) {
  if (!dep) return clc();

  for (int i = pos; i < cnt; i++) {
    bv[i] = true;
    r = std::min(r, sol(dep - 1, i + 1));
    bv[i] = false;
  }

  return r;
}

int main() {
  scanf("%d %d", &n, &m);
  for (y = 0; y < n; y++) {
    for (x = 0; x < n; x++) {
      scanf("%d", &o);
      if (o == 1) vv[y][x] = -1;
      if (o != 2) continue;
      iv[y][x] = true;
      pv[cnt++] = {y, x};
    }
  }

  r = sol(m, 0);
  printf("%d", r == INF ? -1 : r - 1);
}