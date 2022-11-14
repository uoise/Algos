#include <cstdio>
int n, x, c;
int main() {
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    for (int i = 0; i < n; i++) scanf("%d", &x);
    printf("Case %d: Sorting... done!\n", ++c);
  }
}