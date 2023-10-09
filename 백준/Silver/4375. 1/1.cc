#include <cstdio>

int n, x, c;
int sol() {
  if (n == 1) return 1;
  x = 1, c = 0;
  while (++c) {
    if (!(x % n)) return c;
    x = (x * 10 + 1) % n;
  }
  return 0;
}

int main() { while (scanf("%d\n", &n) > 0) printf("%d\n", sol()); }