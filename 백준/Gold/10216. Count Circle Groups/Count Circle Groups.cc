#include <cstdio>
#include <cstring>

constexpr int MX = 3001;
bool bv[MX];
int n, gv[MX], vv[MX][3];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool rch(const int& x, const int& y) {
  int tx = (vv[x][0] - vv[y][0]);
  int ty = (vv[x][1] - vv[y][1]);
  int tr = (vv[x][2] + vv[y][2]);
  return ((tx * tx) + (ty * ty)) <= (tr * tr);
}

void mks(const int& x, const int& y) {
  int gx = fnd(x), gy = fnd(y);
  if (gx == gy || !rch(x, y)) return;
  gv[gx] = gy;
}

int sol() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &vv[i][0], &vv[i][1], &vv[i][2]);
    gv[i] = i;
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (fnd(i) != fnd(j)) mks(i, j);
  int r = 0;
  for (int i = 0; i < n; i++)
    if (!bv[fnd(i)]) ++r, bv[fnd(i)] = 1;
  memset(bv, 0, sizeof bv);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}