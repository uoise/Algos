#include <cstdio>
int vv[25], x, y, c, r, l, res;
int main() {
  for (int i = 0; i < 25; i++) scanf("%d", &vv[i]);
  for (int n = 1; n < 26; n++) {
    scanf("%d", &x);
    if (c + r + l < 3) {
      for (int p = 0; p < 25; p++)
        if (x == vv[p]) {
          vv[p] = 0;
          y = p / 5, x = p % 5;
          break;
        }

      if (!r && (x == y)) {
        r++;
        for (int i = 0; i < 5; i++)
          if (vv[i * 5 + i]) {
            r--;
            break;
          }
      }

      if (!l && (x + y == 4)) {
        l++;
        for (int i = 0; i < 5; i++)
          if (vv[i * 5 + (4 - i)]) {
            l--;
            break;
          }
      }

      int xx = 0, yy = 0;
      for (int i = 0; i < 5; i++) {
        if (!vv[i * 5 + x]) xx++;
        if (!vv[y * 5 + i]) yy++;
      }
      if (xx == 5) c++;
      if (yy == 5) c++;
      if (c + l + r >= 3) res = n;
    }
  }
  printf("%d", res);
}