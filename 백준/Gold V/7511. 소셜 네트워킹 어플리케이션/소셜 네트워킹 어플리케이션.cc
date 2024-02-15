#include <cstdio>

constexpr int MX = 1e6 + 1;
int gv[MX];
int fnd(int x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return;
  gv[x] = y;
}

void sol() {
  int n, k, s, e;
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n; i++) gv[i] = i;
  while (k--) {
    scanf("%d %d", &s, &e);
    mks(s, e);
  }

  scanf("%d", &k);
  while (k--) {
    scanf("%d %d", &s, &e);
    printf("%d\n", fnd(s) == fnd(e));
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Scenario %d:\n", i);
    sol();
    printf("\n");
  }
}