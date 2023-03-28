#include <algorithm>
#include <cstdio>

int n, m, v[8], b[8], r[8];
void sol(int len) {
  if (len == m) {
    for (int i = 0; i < m; i++) printf("%d ", r[i]);
    printf("\n");
  } else {
    int t = -1;
    for (int i = 0; i < n; i++) {
      if (b[i] || t == v[i]) continue;
      t = r[len] = v[i], b[i] = 1;
      sol(len + 1);
      b[i] = 0;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  sol(0);
}