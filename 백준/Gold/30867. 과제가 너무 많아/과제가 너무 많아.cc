#include <cstdio>

constexpr int M = 2e5 + 1;
int n, l, p, c;
char s[M], r[M];
int main() {
  scanf("%d %d %s", &l, &n, s);
  for (int i = 0; i < l; i++) {
    if (s[i] == 'w') {
      if (++c > n) {
        c = n;
        r[p++] = 'w';
      }
    } else if (s[i] == 'h') {
      r[p++] = 'h';
    } else {
      while (c--) r[p++] = 'w';
      r[p++] = s[i], c = 0;
    }
  }
  while (c--) r[p++] = 'w';
  r[p++] = '\0';
  printf("%s", r);
}