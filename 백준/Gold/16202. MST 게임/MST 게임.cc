#include <cstdio>

int n, m, k, c, r, s, gv[1001], vv[10001][2];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return false;
  gv[x] = y;
  return true;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) scanf("%d %d", &vv[i][0], &vv[i][1]);
  while (k--) {
    for (int i = 0; i <= n; i++) gv[i] = i;
    c = 10002, r = 0, s = 0;

    for (int i = 0; i < m; i++) {
      if (!vv[i][0] || !vv[i][1]) continue;
      if (mks(vv[i][0], vv[i][1])) r += i + 1, c = i < c ? i : c, ++s;
    }
    if (c != 10002) vv[c][0] = vv[c][1] = 0;
    printf("%d ", s == n - 1 ? r : 0);
  }
}