#include <algorithm>
#include <cstdio>
int n, m, v[2000001];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n + m; i++) scanf("%d", &v[i]);
  std::sort(v, v + n + m);
  for (int i = 0; i < n + m; i++) printf("%d ", v[i]);
}