#include <algorithm>
#include <cstdio>

using ll = long long;

constexpr ll MX = 1e9 + 7;
int n, v[300000];
ll pow(int e) {
  if (!e) return 1;
  if (e == 1) return 2;
  ll r = pow(e / 2) % MX;
  return r * r * (e & 1 ? 2L : 1L) % MX;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  ll res = 0;
  for (int i = 0; i < n; i++)
    res = (res + v[i] * (pow(i) - pow(n - 1 - i))) % MX;
  printf("%d", res);
}