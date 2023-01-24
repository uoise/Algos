#include <algorithm>
#include <cstdio>

long long v[100000], n, x, c, r, y;
int main() {
  scanf("%d", &n);
  for (auto i = 0; i < n; i++) scanf("%lld", &v[i]);
  std::sort(v, v + n);
  r = x = v[0], y = c = 1;
  for (auto i = 1; i < n; i++) {
    if (x != v[i]) {
      r = y < c ? x : r;
      y = y < c ? c : y;
      x = v[i], c = 1;
    } else {
      c++;
    }
  }
  r = y < c ? x : r;
  y = y < c ? c : y;
  printf("%lld", r);
}