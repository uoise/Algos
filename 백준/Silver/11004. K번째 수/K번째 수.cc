#include <algorithm>
#include <cstdio>
int n, k, v[5000000];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  printf("%d", v[k - 1]);
}