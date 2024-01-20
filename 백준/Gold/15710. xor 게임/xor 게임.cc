#include <cstdio>

using ll = long long;

constexpr ll R = 1e9 + 7LL;
ll clc(ll b, int p) {
  b %= R;
  ll r = 1;
  while (p) {
    if (p % 2) r = (r * b) % R;
    b = (b * b) % R;
    p >>= 1;
  }
  return r;
}

int main() {
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);
  printf("%lld", clc(2147483648LL, n - 1));
}