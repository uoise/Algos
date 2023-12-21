#include <algorithm>
#include <cstdio>

using ll = long long;
constexpr ll MX = 25e4 + 1;
int n, c[MX];
ll v[MX], s;
ll sol() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    s += v[i];
  }
  if (!s) return n / 2;
  for (int i = 1, j; i <= n; i++) {
    if (v[i] || c[i]) continue;
    for (j = i; j <= n && !v[j]; j++) c[j] = 1;
    s += (j - i + 1) / 2;
  }
  return s;
}

int main() { printf("%lld", sol()); }