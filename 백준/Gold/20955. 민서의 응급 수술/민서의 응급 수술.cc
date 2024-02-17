#include <cstdio>

constexpr int MX = 1e5 + 1;
int gv[MX];
int fnd(int x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  gv[x] = y;
  return 1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) gv[i] = i;
  int r = 0;
  while (m--) {
    int s, e;
    scanf("%d %d", &s, &e);
    if (!mks(s, e)) ++r;
  }

  for (int i = 1; i <= n; i++) r += mks(1, i);
  printf("%d", r);
}