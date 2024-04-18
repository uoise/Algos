#include <algorithm>
#include <cstdio>

using ll = long long;

int n, v[100001];
ll sol(int s, int e) {
  if (s == e) return 1LL * v[s] * v[s];
  if (s > e) return 0;

  ll r = std::max(sol(s, (s + e) / 2), sol((s + e) / 2 + 1, e));
  int ml = (s + e) / 2, mr = (s + e) / 2 + 1;
  int tm = std::min(v[ml], v[mr]);
  ll ts = v[ml] + v[mr];
  ll tr = 1LL * ts * tm;
  while (ml > s || mr < e) {
    if (ml > s && (mr == e || v[ml - 1] > v[mr + 1])) {
      tm = std::min(tm, v[--ml]);
      ts += v[ml];
    } else {
      tm = std::min(tm, v[++mr]);
      ts += v[mr];
    }
    tr = std::max(tr, 1LL * ts * tm);
  }

  return std::max(r, tr);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  printf("%lld", sol(0, n - 1));
}