#include <cstdio>
int v[100][100], n, m, x;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &v[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &x);
      v[i][j] += x;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", v[i][j]);
    printf("\n");
  }
}