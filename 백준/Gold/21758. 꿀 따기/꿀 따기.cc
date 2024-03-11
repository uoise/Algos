#include <algorithm>
#include <cstdio>

constexpr int MX = 1e5 + 1;
int n, v[MX], s[MX], r;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    s[i] = v[i] + s[i - 1];
  }

  for (int i = 2; i < n; i++) {
    r = std::max(r, s[n] - v[1] - v[i] + s[n] - s[i]);
    r = std::max(r, s[i] - v[1] + s[n - 1] - s[i - 1]);
    r = std::max(r, s[i - 1] + s[n - 1] - v[i]);
  }

  printf("%d", r);
}