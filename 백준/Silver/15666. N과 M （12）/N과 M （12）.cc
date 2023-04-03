#include <algorithm>
#include <cstdio>

int n, m, v[8], r[8];
void sol(int len, int idx) {
  if (len == m) {
    for (int i = 0; i < m; i++) printf("%d ", r[i]);
    printf("\n");
    return;
  }
  int tmp = -1;
  for (int i = idx; i < n; i++) {
    if (tmp == v[i]) continue;
    r[len] = v[i];
    tmp = r[len];
    sol(len + 1, i);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  sol(0, 0);
}