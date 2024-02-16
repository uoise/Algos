#include <algorithm>
#include <cstdio>

constexpr int MX = 1e6 + 2;
int n, v[MX], p[MX], q[MX], r, t, s;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) p[i] = gcd(v[i], p[i - 1]);
  for (int i = n; i; i--) q[i] = gcd(v[i], q[i + 1]);
  r = p[n];
  for (int i = 1; i <= n; i++) {
    if (!(p[i - 1] || q[i + 1])) continue;
    t = gcd(std::max(p[i - 1], q[i + 1]), std::min(p[i - 1], q[i + 1]));
    if (!(v[i] % t) || r >= t) continue;
    r = t, s = i;
  }

  if (s)
    printf("%d %d", r, v[s]);
  else
    printf("-1");
}