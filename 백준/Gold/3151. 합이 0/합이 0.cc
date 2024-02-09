#include <algorithm>
#include <cstdio>

long long c;
int n, v[10001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      long long s = -v[i] - v[j];
      int l = std::lower_bound(v + j + 1, v + n, s) - v;
      int r = std::upper_bound(v + j + 1, v + n, s) - v;
      c += r - l;
    }
  }
  printf("%lld", c);
}