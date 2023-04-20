#include <algorithm>
#include <cstdio>

bool chk;
long long b, e, l, r, x, y, n, res;
bool sol() {
  scanf("%lld %lld", &b, &e);
  scanf("%lld %lld", &x, &y);
  if (b > e) std::swap(b, e);
  if (x < 0L) x *= -1L;
  if (x <= y || y < 0) return 0;

  l = (b - x) / x - 1;
  r = (e + x) / x + 1;
  for (long long i = l; i <= r; i++) {
    n = i * x + y;
    if (n >= b && n <= e) {
      if (chk) return 0;
      chk = 1, res = n;
    }
  }
  return chk;
}

int main() {
  if (sol())
    printf("%lld", res);
  else
    printf("Unknwon Number");
}