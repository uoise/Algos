#include <cstdio>
int main() {
  int n, l, d, r, g, c = 0, x = 0;
  scanf("%d %d", &n, &l);
  while (n--) {
    scanf("%d %d %d", &d, &r, &g);
    x += (d - c);
    if ((x % (r + g)) < r) x += (r - (x % (r + g)));
    c = d;
  }
  printf("%d", (d < l ? x + (l - d) : x));
}