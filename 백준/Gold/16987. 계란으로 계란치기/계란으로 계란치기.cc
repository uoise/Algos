#include <cstdio>

int n, s[8], w[8], r;
void sol(int c) {
  if (c == n) {
    int t = 0;
    for (int i = 0; i < n; i++)
      if (s[i] < 1) ++t;
    r = r < t ? t : r;
    return;
  }

  int t = 0;
  for (int i = 0; i < n; i++)
    if (s[i] > 0) ++t;
  if (s[c] < 1 || t == 1) {
    sol(c + 1);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (i == c || s[i] < 1) continue;
    s[c] -= w[i], s[i] -= w[c];
    sol(c + 1);
    s[c] += w[i], s[i] += w[c];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &s[i], &w[i]);
  if (n > 1) sol(0);
  printf("%d", r);
}