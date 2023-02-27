#include <cstdio>

int T, n, v[101];
long long r;
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) r += gcd(v[i], v[j]);
    printf("%lld\n", r);
    r = 0;
  }
}