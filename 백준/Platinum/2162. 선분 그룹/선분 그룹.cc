#include <algorithm>
#include <cstdio>

using pi = std::pair<int, int>;
pi v[3001][2];
int n, gv[3001], rv[3001];
int ccw(const pi& a, const pi& b, const pi& c) {
  int r = (b.first - a.first) * (c.second - a.second) -
          (c.first - a.first) * (b.second - a.second);
  return r < 0 ? -1 : (r > 0 ? 1 : 0);
}

int fnd(int x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  if (fnd(x) == fnd(y)) return;
  int xy = ccw(v[x][0], v[x][1], v[y][0]) * ccw(v[x][0], v[x][1], v[y][1]),
      yx = ccw(v[y][0], v[y][1], v[x][0]) * ccw(v[y][0], v[y][1], v[x][1]);
  if (!xy && !yx && (v[y][0] > v[x][1] || v[x][0] > v[y][1])) return;
  if (xy > 0 || yx > 0) return;
  gv[fnd(x)] = fnd(y);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) scanf("%d %d", &v[i][j].first, &v[i][j].second);
    if (v[i][0] > v[i][1]) std::swap(v[i][0], v[i][1]);
    gv[i] = i;
  }

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) mks(i, j);

  int ct = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    int t = fnd(i);
    if (!rv[t]++) ++ct;
    mx = std::max(mx, rv[t]);
  }
  printf("%d\n%d", ct, mx);
}