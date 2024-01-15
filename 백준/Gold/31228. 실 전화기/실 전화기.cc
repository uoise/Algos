#include <cstdio>
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
long long sol(int n, int k) {
  if (n % k == 0) return 0;
  while (1) {
    int g = gcd(n, k);
    if (g == 1) break;
    n /= g, k /= g;
  }
  while (k > n / 2) k = n - k;
  return 1LL * n * (k - 1);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%lld", sol(n, k));
}