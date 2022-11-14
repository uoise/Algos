#include <cstdio>
int n, t, h, m, r[2], g[2], b, e, c;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d:%d", &t, &h, &m);
    g[t - 1]++;
    if (g[0] == g[1]) {
      e = h * 60 + m;
      if (c) r[c - 1] += (e - b);
      c = 0;
    } else {
      int x = c;
      c = g[0] > g[1] ? 1 : 2;
      if (x != c) b = h * 60 + m;
    }
  }
  if (c) r[c - 1] += (48 * 60 - b);
  printf("%02d:%02d\n%02d:%02d", r[0] / 60, r[0] % 60, r[1] / 60, r[1] % 60);
}