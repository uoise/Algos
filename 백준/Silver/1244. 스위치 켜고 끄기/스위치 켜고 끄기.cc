#include <cstdio>

int main() {
  int n, m, s, v;
  scanf("%d", &n);
  bool vv[n + 1];
  for (int i = 1; i <= n; i++) scanf("%d", &vv[i]);

  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &s, &v);
    if (s & 1) {
      for (int i = 1; i <= n; i++) {
        if (!(i % v)) vv[i] = (vv[i] ? 0 : 1);
      }
    } else {
      int beg = v, end = v;
      while (beg > 1 && end < n) {
        if (!(vv[beg - 1] ^ vv[end + 1]))
          beg--, end++;
        else
          break;
      }
      for (int i = beg; i <= end; i++) vv[i] = (vv[i] ? 0 : 1);
    }
  }

  for (int i = 1; i <= n; i += 20) {
    for (int j = i; j < i + 20 && j <= n; j++) printf("%d ", vv[j]);
    printf("\n");
  }
}
