#include <algorithm>
#include <cstdio>

constexpr int MX = 1e5 + 1;
int n, k, v[MX], m[MX], l, s;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  s = v[l];
  for (int i = 1; i <= n; i++) {
    m[i] = std::max(m[i - 1], m[l] + s - k);
    while (s >= k) s -= v[l++];
    s += v[i];
  }

  printf("%d", m[n]);
}