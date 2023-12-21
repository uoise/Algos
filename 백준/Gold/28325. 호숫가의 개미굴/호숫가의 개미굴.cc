#include <algorithm>
#include <cstdio>
#include <numeric>

using ll = long long;
constexpr ll MX = 25e4 + 1;
int n, c[MX];
ll v[MX];
ll sol() {
  scanf("%d", &n);
  ll s = 0, m = -1;
  int p = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    s += v[i];
    if (v[i] > m) m = v[i], p = i;
  }
  if (!s) return n / 2;
  std::rotate(v + 1, v + p, v + n + 1);
  for (int i = 1, j; i <= n; i++) {
    if (v[i] || c[i]) continue;
    for (j = i; j <= n && !v[j]; j++) c[j] = 1;
    s += (j - i + 1) / 2;
  }
  return s;
}

int main() { printf("%lld", sol()); }