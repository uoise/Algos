#include <cstdio>

using ll = long long;
constexpr ll c = 1e9 + 7;
constexpr int MX = 4e6 + 1;
ll dp[MX];
ll pow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) r = r * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return r;
}

ll sol() {
  ll n, k, x, y;
  scanf("%lld %lld", &n, &k);
  x = dp[n], y = dp[k] * dp[n - k] % c;
  return x * pow(y, c - 2) % c;
}

int main() {
  dp[0] = 1;
  for (int i = 1; i < MX; i++) dp[i] = dp[i - 1] * i % c;
  int m;
  scanf("%d", &m);
  while (m--) printf("%lld\n", sol());
}