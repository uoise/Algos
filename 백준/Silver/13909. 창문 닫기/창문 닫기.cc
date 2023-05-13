#include <cstdio>

int n, r;
int main() {
  scanf("%d", &n);
  for (int i = 1; i * i <= n; i++) r++;
  printf("%d", r);
}