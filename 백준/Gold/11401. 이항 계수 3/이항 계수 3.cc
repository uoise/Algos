#include <iostream>
int n, k, c = 1000000007;

long long pow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return pow(a, b - 1) * a % c;
  long long r = pow(a, b / 2) % c;
  return r * r % c;
}

long long solve() {
  long long u = 1, d = 1;
  for (int i = n - k + 1; i <= n; i++) u = u * i % c;
  for (int i = 1; i <= k; i++) d = d * i % c;
  d = pow(d, c - 2);
  return u * d % c;
}

int main() {
  scanf("%d %d", &n, &k);
  printf("%d\n", solve());
}