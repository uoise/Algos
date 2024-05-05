#include <algorithm>
#include <cstdio>

int n, v[100001], l, r = 1;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  for (int i = 1; i < n; i++) if (v[i] >= v[l] * 2) ++r, l = i;
  printf("%d", r);
}