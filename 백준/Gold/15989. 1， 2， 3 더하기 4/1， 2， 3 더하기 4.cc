#include <cstdio>

constexpr int MX = 1e4 + 1;
int n, v[MX][4];
int main() {
  v[0][1] = v[1][1] = 1;
  for (int i = 2; i < MX; i++) {
    v[i][1] = v[i - 1][1];
    v[i][2] = v[i - 2][1] + v[i - 2][2];
    v[i][3] = v[i - 3][1] + v[i - 3][2] + v[i - 3][3];
  }

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", v[n][1] + v[n][2] + v[n][3]);
  }
}