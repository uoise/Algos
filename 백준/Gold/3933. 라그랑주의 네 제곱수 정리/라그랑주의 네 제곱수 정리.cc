#include <cstdio>
int n, r;
int main() {
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    r = 0;
    for (int i = 1; i * i <= n; i++) {
      if (i * i == n) ++r;
      for (int j = i; i * i + j * j <= n; j++) {
        if (i * i + j * j == n) ++r;
        for (int k = j; i * i + j * j + k * k <= n; k++) {
          if (i * i + j * j + k * k == n) ++r;
          for (int l = k; i * i + j * j + k * k + l * l <= n; l++) {
            if (i * i + j * j + k * k + l * l == n) ++r;
          }
        }
      }
    }
    printf("%d\n", r);
  }
}