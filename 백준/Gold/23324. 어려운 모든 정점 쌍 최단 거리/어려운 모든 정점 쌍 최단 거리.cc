#include <cstdio>

int n, gv[100001];
int fnd(int x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x != y) gv[x] = y;
}

int main() {
  int m, k, s, e;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) gv[i] = i;
  while (m--) {
    scanf("%d %d", &s, &e);
    if (--k) mks(s, e);
  }

  s = 0, e = 0, m = fnd(1);
  for (int i = 1; i <= n; i++) m == fnd(i) ? ++s : ++e;
  printf("%lld", 1LL * s * e);
}