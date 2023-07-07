#include <cstdio>

constexpr int MX = 1e5 + 2;
int i, n, m, h, l, r, v[MX], s[MX];
int main() {
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);

  while (m--) {
    scanf("%d %d %d", &l, &r, &h);
    s[l] += h, s[r + 1] -= h;
  }

  for (i = 1; i <= n; i++) {
    s[i] += s[i - 1];
    printf("%d ", v[i] + s[i]);
  }
}