#include <iostream>

void solve() {
  int x, y;
  int t, r = 0;
  scanf("%d", &x);
  scanf("%d", &y);
  for (t = (x > y) ? y : x; t > 0 && !r; t--)
    if ((x % t == 0) && (y % t == 0)) r = t;
  printf("%d\n%d\n", r, x * y / r);
}

int main() { solve(); }