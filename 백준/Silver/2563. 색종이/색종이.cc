#include <cstdio>
bool v[100][100];
int n, x, y, r;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++) v[i + y][j + x] = 1;
  }
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      if (v[i][j]) r++;
  printf("%d", r);
}