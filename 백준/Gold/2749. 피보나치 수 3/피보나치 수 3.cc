#include <cstdio>
#include <cstring>

using ll = long long;
constexpr ll MX = 1e6;
ll n, tv[2][2], fv[2][2] = {{1, 1}, {1, 0}}, rv[2][2] = {{1, 0}, {0, 1}};
void pow(ll x[][2], ll y[][2]) {
  memset(tv, 0, sizeof tv);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        tv[i][k] = (tv[i][k] + x[i][j] * y[j][k]) % MX;
  memcpy(x, tv, sizeof tv);
}

int main() {
  scanf("%lld", &n);
  --n;
  while (n) {
    if (n % 2) pow(rv, fv);
    pow(fv, fv);
    n /= 2;
  }
  printf("%d", rv[0][0]);
}