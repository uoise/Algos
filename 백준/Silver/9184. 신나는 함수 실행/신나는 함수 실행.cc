#include <iostream>
#define MAX 21
int va[MAX][MAX][MAX];

int w(int a, int b, int c) {
  if ((a < 1) || (b < 1) || (c < 1)) return 1;
  if (a > MAX - 1 || b > MAX - 1 || c > MAX - 1) {
    a = b = c = 20;
  }
  for (int ia = 1; ia <= a; ia++)
    for (int ib = 1; ib <= b; ib++)
      for (int ic = 1; ic <= c; ic++) {
        if ((ia < ib) && (ib < ic))
          va[ia][ib][ic] =
              va[ia][ib][ic - 1] + va[ia][ib - 1][ic - 1] - va[ia][ib - 1][ic];
        else
          va[ia][ib][ic] = va[ia - 1][ib][ic] + va[ia - 1][ib - 1][ic] +
                           va[ia - 1][ib][ic - 1] - va[ia - 1][ib - 1][ic - 1];
      }
  return va[a][b][c];
}

int main() {
  int v1, v2, v3;
  for (v1 = 0; v1 < MAX; v1++)
    for (v2 = 0; v2 < MAX; v2++)
      for (v3 = 0; v3 < MAX; v3++) va[v1][v2][v3] = 1;
  while (true) {
    scanf("%d", &v1);
    scanf("%d", &v2);
    scanf("%d", &v3);
    if ((v1 == -1) && (v2 == -1) && (v3 == -1)) break;
    printf("w(%d, %d, %d) = %d\n", v1, v2, v3, w(v1, v2, v3));
  }
}