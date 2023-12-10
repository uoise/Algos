#include <cstdio>

int xcr(int x) {
  int r = 0;
  for (int i = (x >> 2) << 2; i <= x; i++) r ^= i;
  return r;
}

int main() {
  int T, s, e;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &s, &e);
    printf("%d\n", xcr(e) ^ xcr(s - 1));
  }
}