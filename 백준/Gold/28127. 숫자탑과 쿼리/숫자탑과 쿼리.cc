#include <algorithm>
#include <cstdio>

std::pair<int, int> sol(long long a, long long d, long long x) {
  std::pair<int, int> p;
  int l = 1, r = 1e6 + 1, m;
  while (l <= r) {
    m = (l + r) / 2;
    long long s = (1 + a * (m - 1) + d * (m - 1) * (m - 2) / 2);
    if (s <= x) l = m + 1, p = {m, x - s + 1};
    else r = m - 1;
  }
  return p;
}

int main() {
  int q, a, d, x;
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &a, &d, &x);
    auto [h, w] = sol(a, d, x);
    printf("%d %d\n", h, w);
  }
}