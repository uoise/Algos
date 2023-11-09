#include <algorithm>
#include <cstdio>

int n, p[100001];
long long v[100001];
long long sol(int x) {
  long long r = 0;
  auto f = std::lower_bound(p, p + n, x) - p;
  r += (1LL * f * x - v[f - 1]);
  r += ((v[n - 1] - v[f - 1]) - 1LL * (n - f) * x);
  return r;
}

int main() {
  int q, x;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  std::sort(p, p + n);
  v[0] = p[0];
  for (int i = 1; i < n; i++) v[i] = v[i - 1] + p[i];
  while (q--) {
    scanf("%d", &x);
    printf("%lld\n", sol(x));
  }
}