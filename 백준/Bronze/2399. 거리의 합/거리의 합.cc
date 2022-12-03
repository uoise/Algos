#include <algorithm>
#include <cstdio>
long long n, r, v[10000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  for (int i = 0; i < n; i++) r += (v[i] * (2 * i - n + 1));
  printf("%lld", r * 2);
}