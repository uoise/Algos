#include <algorithm>
#include <cstdio>
#include <cstring>

using ll = long long;

int n, k, v[16];
ll d[16][1 << 16], r;
ll sol(int c, int b) {
  if (b == (1 << n) - 1) return 1;
  ll& t = d[c][b];
  if (t != -1) return t;
  t = 0;
  for (int i = 0; i < n; i++) {
    if ((b & (1 << i)) || (std::abs(v[c] - v[i]) <= k)) continue;
    t += sol(i, b | (1 << i));
  }
  return t;
}

int main() {
  memset(d, -1, sizeof d);
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) r += sol(i, 1 << i);
  printf("%lld", r);
}