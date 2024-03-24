#include <cstdio>

int n, x, y, v[33], r;
bool b[33];
void btr(int c) {
  if (c == n * 2) {
    ++r;
    return;
  }

  if (v[c]) {
    btr(c + 1);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (b[i] || c + i + 1 > 2 * n || v[c + i + 1]) continue;
    v[c] = v[c + i + 1] = i;
    b[i] = 1;
    btr(c + 1);
    v[c] = v[c + i + 1] = b[i] = 0;
  }
}

int main() {
  scanf("%d %d %d", &n, &x, &y);
  v[x] = v[y] = y - x - 1;
  b[y - x - 1] = 1;
  btr(1);
  printf("%d", r);
}