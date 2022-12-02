#include <algorithm>
#include <cstdio>
int v[8], r[8], b[8], n, m;
void sol(int c) {
  if (c == m) {
    for (int i = 0; i < m; i++) printf("%d ", v[r[i]]);
    printf("\n");
  } else {
    for (int i = 0; i < n; i++)
      if (!b[i]) {
        r[c] = i, ++b[i];
        sol(c + 1);
        --b[i];
      }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  sol(0);
}