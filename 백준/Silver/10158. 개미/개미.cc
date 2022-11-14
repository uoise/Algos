#include <iostream>

int main() {
  int w, h, x, y, t;
  scanf("%d %d %d %d %d", &w, &h, &x, &y, &t);
  int xx[2 * w], yy[2 * h];
  bool neg = false;
  int i = x, c = 0;
  while (c <= 2 * w) {
    if (!neg) {
      xx[c++] = i++;
      if (i == w) neg = true;
    } else {
      xx[c++] = i--;
      if (i == 0) neg = false;
    }
  }
  i = y, c = 0;
  while (c <= 2 * h) {
    if (!neg) {
      yy[c++] = i++;
      if (i == h) neg = true;
    } else {
      yy[c++] = i--;
      if (i == 0) neg = false;
    }
  }
  printf("%d %d", xx[t % (2 * w)], yy[t % (2 * h)]);
}