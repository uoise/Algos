#include <algorithm>
#include <cmath>
#include <cstdio>

using ll = long long;

int n;
ll v[101][2], r1, r2;
ll gcd(const ll& x, const ll& y) {
  if (y) return gcd(y, x % y);
  return x;
}

ll clc(int x) {
  for (int i = 0; i < n; i++) scanf("%d", &v[i][x]);
  ll r = v[0][x];
  for (int i = 1; i < n; i++) r = gcd(r, v[i][x]);

  return r;
}

int main() {
  scanf("%d %d", &n);
  ll g1 = clc(0), g2 = clc(1), lc = 1;
  for (int i = 0; i < n; i++) {
    v[i][0] /= g1;
    v[i][1] /= g2;
    r1 += v[i][0];
  }
  for (int i = 0; i < n; i++)
    lc = std::max(lc, (ll)ceil((double)v[i][0] / v[i][1]));
  for (int i = 0; i < n; i++) r2 += v[i][1] * lc;

  printf("%lld %lld", r1, r2);
}