#include <algorithm>
#include <cstdio>

constexpr int MX = 100001;
int n, g, r, v[MX], l[MX];
int gcd(int x, int y) {
  while (y) {
    int t = x % y;
    x = y;
    y = t;
  }
  return x;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  for (int i = 1; i < n; i++) l[i - 1] = v[i] - v[i - 1];
  g = l[0];
  for (int i = 1; i < n - 1; i++) g = gcd(g, l[i]);
  for (int i = 0; i < n - 1; i++) r += (l[i] / g) - 1;
  printf("%d", r);
}