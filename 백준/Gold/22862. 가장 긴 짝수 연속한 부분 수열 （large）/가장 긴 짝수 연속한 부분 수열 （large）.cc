#include <algorithm>
#include <cstdio>

int n, k, v[1000001], r, s, e, c;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  c = v[e] % 2;
  while (s < n && e < n) {
    r = std::max(r, e - s + 1 - c);
    if (c > k) c -= v[s++] % 2;
    else c += v[++e] % 2;
  }
  printf("%d", r);
}