#include <cstdio>
#include <cstring>

using ll = long long;

constexpr ll MX = 1e9;
void pow(ll r[][2], ll a[][2]) {
  ll t[2][2] = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) t[i][k] = (t[i][k] + r[i][j] * a[j][k]) % MX;

  memcpy(r, t, sizeof t);
}

ll sol(ll n) {
  ll a[2][2] = {{1, 1}, {1, 0}}, r[2][2] = {{1, 0}, {0, 1}};
  while (n) {
    if (n & 1LL) pow(r, a);
    pow(a, a);
    n >>= 1;
  }

  return (r[0][0] - 1 + MX) % MX;
}

int main() {
  ll a, b;
  scanf("%lld %lld", &a, &b);
  b = sol(b + 1) - sol(a);
  printf("%lld", (b + MX) % MX);
}