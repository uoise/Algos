#include <cstdio>
int n, x, v[1001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &x);
      v[i] |= x;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
}