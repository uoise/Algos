#include <cstdio>
long long n, t = 2, r = 1;
long long sol() {
  scanf("%lld", &n);
  if (n < 4) return n == 1 ? 10 : 11;
  while (n < t / 2 || n >= t) t *= 2, ++r;
  return r + 9;
}
int main() { printf("%lld", sol()); }