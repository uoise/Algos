#include <cstdio>
#include <queue>

int n, gv[100001];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  gv[x] = y;
}

int main() {
  int m, s, e, r = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d", &s, &e);
    mks(s, e);
  }

  s = 0;
  while (n--) {
    scanf("%d", &e);
    if (fnd(s) != fnd(e)) ++r;
    s = e;
  }

  printf("%d", r - 1);
}