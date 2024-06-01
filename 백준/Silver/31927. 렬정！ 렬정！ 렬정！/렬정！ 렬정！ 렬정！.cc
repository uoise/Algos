#include <cstdio>
int n, a[101], t = 1e6;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("%d", n / 2);
  for (int i = 0; i < n / 2; i++) {
    a[i] += t, a[n - 1 - i] -= t;
    t -= 5001;
    printf("\n");
    for (int j = 0; j < n; j++) printf("%d ", a[j]);
  }
}