#include <algorithm>
#include <cstdio>

constexpr int MN = 1e6 + 1;
int n, k, x, r = MN * 2;
bool v[MN];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    v[i] = x == 1;
  }
  int s = 0, e = 1, c = v[1];
  while (e <= n) {
    if (c < k) {
      c += v[++e];
    } else {
      r = std::min(r, e - s);
      c -= v[++s];
    }
  }
  printf("%d", r > n ? -1 : r);
}