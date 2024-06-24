#include <algorithm>
#include <cstdio>

constexpr int MN = 1e5 + 1;

std::pair<int, int> v[MN];
int n, a[MN], q, r[MN], t;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &v[i].first);
    v[i].second = i;
  }

  std::sort(v, v + q);

  for (int i = 0; i < q; i++) {
    auto [x, p] = v[i];
    x -= t;
    while (x > a[t] && t < n) t++, x--;
    r[p] = t + 1;
  }

  for (int i = 0; i < q; i++) printf("%d ", r[i]);
}