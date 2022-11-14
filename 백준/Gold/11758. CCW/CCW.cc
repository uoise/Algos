#include <cstdio>
int main() {
  int x[3], y[3];
  scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
  int r = x[0] * y[1] + x[1] * y[2] + x[2] * y[0];
  r = r - x[1] * y[0] - x[2] * y[1] - x[0] * y[2];
  printf("%d", (r < 0 ? -1 : (r > 0 ? 1 : 0)));
}