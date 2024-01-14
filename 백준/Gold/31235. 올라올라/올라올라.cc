#include <cstdio>
int n, x, m, l, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (!i) {
      m = x, l = 1;
      continue;
    }
    if (m > x) {
      ++l;
    } else {
      m = x, r = l > r ? l : r;
      l = 1;
    }
  }
  r = l > r ? l : r;
  printf("%d", r);
}