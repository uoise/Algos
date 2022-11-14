#include <cmath>
#include <iostream>

int main() {
  int n;
  double r = 0;
  scanf("%d", &n);
  long long xx[n], yy[n];
  int p = n - 1;
  for (int i = 0; i < n; i++) scanf("%lld %lld", &xx[i], &yy[i]);
  for (int i = 0; i < n; i++) {
    r += (xx[p] + xx[i]) * (yy[p] - yy[i]);
    p = i;
  }
  if (r < 0) r *= -1;
  printf("%.1lf", round(r * 5) / 10);
}
