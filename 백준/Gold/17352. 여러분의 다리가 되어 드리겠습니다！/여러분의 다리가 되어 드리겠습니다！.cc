#include <cstdio>

int n, gv[300001];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x != y) gv[x] = y;
}

int main() {
  int s, e;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) gv[i] = i;
  for (int i = 2; i < n; i++) {
    scanf("%d %d", &s, &e);
    mks(s, e);
  }

  s = fnd(1);
  for (int i = 2; i <= n; i++)
    if (s != fnd(i)) {
      printf("%d %d", s, i);
      break;
    }
}