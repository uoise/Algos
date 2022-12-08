#include <cstdio>
unsigned int Q, x, r;

bool clc() {
  r = 1;
  while (r <= x) {
    if (r == x) return 1;
    r <<= 1;
  }
  return 0;
}

int main() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &x);
    printf("%d\n", clc());
  }
}