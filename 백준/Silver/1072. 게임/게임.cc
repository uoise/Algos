#include <cstdio>

long long x, y, z, s, e, r = 1e9 + 1;
int main() {
  scanf("%lld %lld", &x, &y);
  e = x, z = y * 100 / x;
  while (s <= e) {
    long long m = (s + e) / 2;
    if (((y + m) * 100 / (x + m)) != z) {
      r = r > m ? m : r;
      e = m - 1;
    } else
      s = m + 1;
  }

  printf("%d", r > x ? -1 : r);
}