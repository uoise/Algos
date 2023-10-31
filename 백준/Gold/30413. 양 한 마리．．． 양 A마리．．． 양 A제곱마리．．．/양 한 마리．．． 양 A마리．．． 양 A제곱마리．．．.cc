#include <cstdio>

constexpr long long M = 1e9 + 7;
long long fpw(long long b, long long e) {
  long long r = 1;
  while (e) {
    if (e & 1) r = r * b % M;
    b = b * b % M, e /= 2;
  }
  return r;
}

long long sol() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  if (a == 1) return b % M;
  return ((fpw(a, b) - 1) % M) * (fpw(a - 1, M - 2) % M) % M;
}

int main() { printf("%lld", sol()); }