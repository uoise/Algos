#include <algorithm>
#include <cstdio>

int n, r[2], v[11][11], b[21], w[21];
void btr(int y, int x, int s, int c) {
  if (x >= n) ++y, x = x % 2 ? 0 : 1;
  if (y >= n) {
    r[c] = std::max(r[c], s);
    return;
  }

  if (v[y][x] && !b[x - y + n - 1] && !w[y + x]) {
    b[x - y + n - 1] = w[y + x] = 1;
    btr(y, x + 2, s + 1, c);
    b[x - y + n - 1] = w[y + x] = 0;
  }

  btr(y, x + 2, s, c);
}

int main() {
  scanf("%d", &n);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%d", &v[y][x]);
  btr(0, 0, 0, 0);
  btr(0, 1, 0, 1);
  printf("%d", r[0] + r[1]);
}