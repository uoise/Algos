#include <cstdio>
int g, l, m, r = 1;
int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
int main() {
  scanf("%d %d", &g, &l);
  m = l / g;
  for (int i = 2; i * i <= m; i++)
    if (!(m % i) && gcd(i, m / i) == 1) r = i;
  printf("%d %d", r * g, (m / r) * g);
}