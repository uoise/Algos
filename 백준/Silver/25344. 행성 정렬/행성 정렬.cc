#include <cstdio>
int n, r = 1;
int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n - 2; i++) {
    scanf("%d", &x);
    r = r * (x / gcd(r, x));
  }
  printf("%d", r);
}