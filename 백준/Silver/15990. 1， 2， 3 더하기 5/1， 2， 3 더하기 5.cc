#include <cstdio>
constexpr int MX = 1e5 + 1, R = 1e9 + 9;
int r[MX][3];
int main() {
  r[1][0] = r[2][1] = 1;
  r[3][0] = r[3][1] = r[3][2] = 1;
  for (int i = 4; i < MX; i++) {
    r[i][0] = (r[i - 1][1] + r[i - 1][2]) % R;
    r[i][1] = (r[i - 2][0] + r[i - 2][2]) % R;
    r[i][2] = (r[i - 3][0] + r[i - 3][1]) % R;
  }
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", ((r[n][0] + r[n][1]) % R + r[n][2]) % R);
  }
}