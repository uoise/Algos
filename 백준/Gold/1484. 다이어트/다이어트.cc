#include <cstdio>
int g, l = 1, r = 2, s, c;
int main() {
  scanf("%d", &g);
  while (l < r) {
    s = r * r - l * l;
    if (s <= g) {
      if (s == g) printf("%d\n", r), c = 1;
      ++r;
    } else {
      ++l;
    }
  }
  if (!c) printf("-1");
}