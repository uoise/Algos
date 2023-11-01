#include <cstdio>

int n, k, v[100001], t, r;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++)
    if (v[i] > t) t = v[i] + k, ++r;
  printf("%d", r);
}