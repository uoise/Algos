#include <cstdio>
int n, v[100001], r;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    if (v[i] == i) ++r, v[i] = i == n ? 1 : n;
  }
  printf("%d\n", r);
  for (int i = 1; i <= n; i++) printf("%d ", v[i]);
}