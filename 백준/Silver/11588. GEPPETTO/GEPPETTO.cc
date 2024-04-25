#include <cstdio>

bool b[21][21], c[21];
int n;
int sol(int x) {
  if (x == n) return 1;
  int r = sol(x + 1);
  for (int i = 0; i < n; i++) if (c[i] && b[x][i]) return r;
  c[x] = 1;
  r += sol(x + 1);
  c[x] = 0;
  return r;
}

int main() {
  int m, x, y;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &x, &y);
    b[x][y] = b[--y][--x] = 1;
  }
  printf("%d", sol(0));
}