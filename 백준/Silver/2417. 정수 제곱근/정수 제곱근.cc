#include <cmath>
#include <cstdio>
unsigned long long n, b, e = 3037000500LL, r; // sqrt(2^63-1)
unsigned long long sol() {
  e = (e < n ? e : n);
  while (b <= e) {
    r = (b + e) / 2;
    if (r * r == n) return r;
    if (r * r > n)
      e = r - 1;
    else
      b = r + 1;
  }
  return b;
}

int main() {
  scanf("%lld", &n);
  printf("%lld", sol());
}