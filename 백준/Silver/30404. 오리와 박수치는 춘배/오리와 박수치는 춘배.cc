#include <cstdio>
int n, k, v, t, r;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    if (v > t) t = v + k, ++r;
  }
  printf("%d", r);
}