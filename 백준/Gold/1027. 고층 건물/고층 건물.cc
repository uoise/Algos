#include <cstdio>

constexpr double MX = 2e9 + 1;

double v[51];
int n, r, c;
int main() {
  double s, e, t;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
  for (int i = 0; i < n; i++) {
    c = 0, s = -MX, e = MX;
    for (int j = i + 1; j < n; j++) {
      t = (v[j] - v[i]) / (double)(j - i);
      if (s < t) ++c, s = t;
    }

    for (int j = i - 1; j >= 0; j--) {
      t = (v[j] - v[i]) / (double)(j - i);
      if (e > t) c++, e = t;
    }

    if (r < c) r = c;
  }

  printf("%d", r);
}