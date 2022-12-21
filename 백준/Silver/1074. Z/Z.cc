#include <cstdio>
int n, r, c, y, x, res;
int xx[] = {0, 1, 0, 1}, yy[] = {0, 0, 1, 1};
int sol() {
  int siz = 1;
  while (r >= siz || c >= siz) siz <<= 1;
  while (siz /= 2) {
    for (int i = 3; i >= 0; i--) {
      if ((r >= y + siz * yy[i]) && (c >= x + siz * xx[i])) {
        res += siz * siz * i;
        y += siz * yy[i], x += siz * xx[i];
        break;
      }
    }
  }
  return res;
}
int main() {
  scanf("%d %d %d", &n, &r, &c);
  printf("%d", sol());
}