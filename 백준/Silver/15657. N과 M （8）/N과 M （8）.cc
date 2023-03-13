#include <algorithm>
#include <cstdio>

int n, m, v[8], r[8];
void sol(const int& l, const int& p) {
  if (l == m) {
    for (int i = 0; i < m; i++) printf("%d ", r[i]);
    printf("\n");
  } else {
    for (int i = p; i < n; i++) {
      r[l] = v[i];
      sol(l + 1, i);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i<n;i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  sol(0, 0);
}