#include <cstdio>

int vv[9][9];
bool yv[9][10], xv[9][10], bv[3][3][10], dne;
bool bck(const int& y, const int& x, const int& v) {
  return yv[y][v] || xv[x][v] || bv[y / 3][x / 3][v];
}
void set(const int& y, const int& x, const int& v, const bool& t) {
  vv[y][x] = t ? v : 0;
  yv[y][v] = xv[x][v] = bv[y / 3][x / 3][v] = t;
}

void sol(const int& d) {
  if (d == 81) dne = 1;
  if (dne) return;
  int yy = d / 9, xx = d % 9;
  if (vv[yy][xx]) {
    sol(d + 1);
    return;
  }
  for (int i = 1; i < 10; i++) {
    if (bck(yy, xx, i)) continue;
    set(yy, xx, i, true);
    sol(d + 1);
    if (dne) return;
    set(yy, xx, i, false);
  }
}

int main() {
  char inp[10];
  for (int y = 0; y < 9; y++) {
    scanf("%s", inp);
    for (int x = 0; x < 9; x++) set(y, x, inp[x] - '0', 1);
  }
  sol(0);
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) printf("%d", vv[y][x]);
    printf("\n");
  }
}