#include <cstdio>

int n, y, x, t;
bool v[100][100];
int main() {
  scanf("%d", &n);
  for (y = 0; y < n; y++)
    for (x = 0; x < n; x++) {
      scanf("%d", &t);
      v[y][x] = t;
    }

  for (int i = 0; i < n; i++)
    for (y = 0; y < n; y++)
      for (x = 0; x < n; x++) v[x][y] = v[x][y] || (v[x][i] && v[i][y]);

  for (y = 0; y < n; y++) {
    for (x = 0; x < n; x++) printf("%d ", v[y][x]);
    printf("\n");
  }
}
