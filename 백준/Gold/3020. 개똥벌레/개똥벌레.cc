#include <algorithm>
#include <cstdio>

constexpr int MX = 1e5 + 1;
int n, h, v[2][MX], r = MX * 3, s, i, t;
int main() {
  scanf("%d %d", &n, &h);
  for (i = 0; i < n / 2; i++) scanf("%d %d", &v[0][i], &v[1][i]);
  for (i = 0; i < 2; i++) std::sort(v[i], v[i] + n / 2);
  i = h;
  while (i--) {
    t = n;
    t -= std::lower_bound(v[0], v[0] + n / 2, i) - v[0];
    t -= std::upper_bound(v[1], v[1] + n / 2, h - i) - v[1];
    if (r > t)
      r = t, s = 1;
    else if (r == t)
      ++s;
  }

  printf("%d %d", r, s);
}