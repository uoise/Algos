#include <cstdio>
int n, l, h, c, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h);
    if (!i) {
      l = h;
      continue;
    }
    if (h < l) {
      ++c;
    } else {
      r = c > r ? c : r;
      c = 0, l = h;
    }
  }
  printf("%d", c > r ? c : r);
}