#include <cstdio>

int v[10], n, b = 1, e = 1;
void clc(int x) {
  while (x) {
    v[x % 10] += e;
    x /= 10;
  }
}

int main() {
  scanf("%d", &n);
  while (b <= n) {
    while (n % 10 != 9 && b <= n) clc(n--);
    if (n < b) break;

    while (b % 10 && b <= n) clc(b++);
    b /= 10, n /= 10;
    for (int i = 0; i < 10; i++) v[i] += (n - b + 1) * e;
    e *= 10;
  }

  for (int i = 0; i < 10; i++) printf("%d ", v[i]);
}