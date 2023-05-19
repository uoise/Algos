#include <cstdio>

int T, m, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &m, &n);
    printf("1\n");
    for (int x = 0; x < n; x++) printf("(0,%d)\n", x);
    for (int x = 0; x < n; x++)
      for (int y = 1; y < m; y++)
        printf("(%d,%d)\n", x % 2 ? m - y : y, n - 1 - x);
  }
}