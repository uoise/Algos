#include <iostream>

void solve() {
  int x, y, r, t;
  scanf("%d", &x);
  scanf("%d", &y);
  t = x*y;
  if (x < y) {
    r = x;
    x = y;
    y = r;
  }
  while (y != 0) {
    r = x % y;
    x = y;
    y = r;
  }
  printf("%d\n", t/x);

}

int main() {
  int N;
  scanf("%d", &N);
  while (N--) solve();
}