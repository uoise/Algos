#include <cstdio>

bool r[3072][6145];
void sol(int n, int y, int x) {
  if (n == 1) {
    r[y++][x + 2] = 1;
    r[y++][x + 1] = r[y][x + 3] = 1;
    for (int i = 0; i < 5; i++) r[y][x + i] = 1;
    return;
  }

  sol(n / 2, y, x + 3 * n / 2);
  sol(n / 2, y + 3 * n / 2, x);
  sol(n / 2, y + 3 * n / 2, x + 3 * n);
}

int main() {
  int n;
  scanf("%d", &n);
  sol(n / 3, 0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) printf("%c", r[i][j] ? '*' : ' ');
    printf("\n");
  }
}