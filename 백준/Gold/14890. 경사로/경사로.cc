#include <cstdio>

int n, l, r, vv[100][100];
void sol(int y, int x, const bool d) {
  int t = vv[y][x], c = 1;
  for (int i = 1; i < n; i++) {
    d ? ++y : ++x;
    if (vv[y][x] == t) {
      ++c;
    } else if (vv[y][x] - 1 == t) {
      if (c < l) return;
      t = vv[y][x], c = 1;
    } else if (vv[y][x] + 1 == t) {
      if (c < 0) return;
      t = vv[y][x], c = 1 - l;
    } else {
      return;
    }
  }

  if (c >= 0) r++;
}

int main() {
  scanf("%d %d", &n, &l);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%d", &vv[y][x]);
  for (int i = 0; i < n; i++) sol(i, 0, 0), sol(0, i, 1);
  printf("%d", r);
}