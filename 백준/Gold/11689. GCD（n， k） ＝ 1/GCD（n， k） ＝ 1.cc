#include <cstdio>

using ll = long long;

// Euler's Phi
int main() {
  ll n, r;
  scanf("%lld", &n);
  r = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i) continue;
    r -= r / i;
    while (n % i == 0) n /= i;
  }
  if (n != 1) r -= r / n;
  printf("%lld", r);
}