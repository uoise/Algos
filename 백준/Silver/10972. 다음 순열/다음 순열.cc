#include <algorithm>
#include <cstdio>

int n, v[10001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);

  if (std::next_permutation(v, v + n))
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
  else
    printf("-1");
}