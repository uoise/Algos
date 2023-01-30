#include <algorithm>
#include <cstdio>

using namespace std;

constexpr int MX = 4000;
int n, m, vv[4][MX], rv[2][MX * MX];
long long r;
int main() {
  scanf("%d", &n);
  m = n * n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++) scanf("%d", &vv[j][i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      rv[0][i * n + j] = vv[0][i] + vv[1][j];
      rv[1][i * n + j] = -(vv[2][i] + vv[3][j]);
    }
  for (int i = 0; i < 2; i++) sort(rv[i], rv[i] + m);
  for (int i = 0; i < m; i++)
    r += (upper_bound(rv[1], rv[1] + m, rv[0][i]) -
          lower_bound(rv[1], rv[1] + m, rv[0][i]));
  printf("%lld", r);
}