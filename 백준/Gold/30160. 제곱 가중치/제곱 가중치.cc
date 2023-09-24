#include <cstdio>

int n;
long long r, v[4][100001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &v[0][i]);
  for (int i = 1; i < 4; i++) {
    v[i][0] = v[0][0];
    for (int j = 1; j < n; j++) v[i][j] = v[i - 1][j] + v[i][j - 1];
  }
  for (int i = 0; i < n; i++) printf("%lld ", 2LL * v[3][i] - v[2][i]);
}