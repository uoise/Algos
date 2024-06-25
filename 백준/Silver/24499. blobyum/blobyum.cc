#include <algorithm>
#include <cstdio>

int n, k, a[100001], r, s;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n + k; i++) {
    s += a[i % n];
    if (i < k) continue;
    s -= a[(i - k) % n];
    r = std::max(r, s);
  }
  printf("%d", r);
}