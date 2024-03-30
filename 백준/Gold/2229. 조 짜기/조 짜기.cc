#include <algorithm>
#include <cstdio>

constexpr int MN = 1001;
int n, v[MN], r[MN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  r[2] = std::abs(v[2] - v[1]);
  for (int i = 3; i <= n; i++) {
    int l = v[i], h = v[i];
    for (int j = i - 1; j >= 0; j--) {
      h = std::max(h, v[j + 1]), l = std::min(l, v[j + 1]);
      r[i] = std::max(r[i], r[j] + h - l);
    }
  }
  printf("%d", r[n]);
}