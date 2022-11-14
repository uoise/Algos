#include <iostream>
void solve() {
  uint32_t x, y, w, h, r;
  scanf("%d", &x);
  r = x;
  scanf("%d", &y);
  if (r > y) r = y;
  scanf("%d", &w);
  if (r > (w - x)) r = w - x;
  scanf("%d", &h);
  if (r > (h - y)) r = h - y;
  printf("%d\n", r);
}

int main() { solve(); }