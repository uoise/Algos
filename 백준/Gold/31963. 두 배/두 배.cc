#include <cstdio>

constexpr int MN = 25e4 + 1;
long long r;
int n, a[MN], v[MN];
int sol(long long x, long long y) {
  x <<= 20;
  for (int i = -20; i < 0; i++) {
    if (x <= y) return i;
    x >>= 1;
  }
  for (int i = 0; i < 20; i++) {
    if (x <= y) return i;
    y <<= 1;
  }
  return 20;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i) v[i] = sol(a[i - 1], a[i]);
  }

  for (int i = 1; i < n; i++) if (v[i] > 0) r += v[i], v[i + 1] += v[i];

  printf("%lld", r);
}