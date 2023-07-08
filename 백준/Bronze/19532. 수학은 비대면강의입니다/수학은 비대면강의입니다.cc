#include <cstdio>
int a, b, c, d, e, f, g, x, y;
void sol() {
  for (x = -999; x < 1000; x++)
    for (y = -999; y < 1000; y++)
      if (a * x + b * y == c && d * x + e * y == f) return;
}
int main() {
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  sol();
  printf("%d %d", x, y);
}