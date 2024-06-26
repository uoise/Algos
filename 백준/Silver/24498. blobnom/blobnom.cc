#include <algorithm>
#include <cstdio>
int n, a[1000001], r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  r = std::max(a[0], a[n - 1]);
  for (int i = 1; i < n - 1; i++) r = std::max(r, a[i] + std::min(a[i - 1], a[i + 1]));
  printf("%d", r);
}