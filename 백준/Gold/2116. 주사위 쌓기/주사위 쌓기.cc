#include <stdio.h>
char vv[10000][6], b[6] = {5, 3, 4, 1, 2, 0};
int n, r, s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 6; j++) scanf("%d", &vv[i][j]);
  for (int k = 0; k < 6; k++) {
    s = 0;
    char pos, val = vv[0][k];
    for (int i = 0; i < n; i++) {
      char cur = 0;
      for (int j = 0; j < 6; j++)
        if (vv[i][j] == val) pos = b[j];
      for (int j = 0; j < 6; j++)
        if (j != pos && j != b[pos] && vv[i][j] > cur) cur = vv[i][j];
      s += cur;
      val = vv[i][pos];
    }
    if (r < s) r = s;
  }
  printf("%d", r);
}