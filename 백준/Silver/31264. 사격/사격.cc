#include <algorithm>
#include <cstdio>

using ll = long long;
constexpr int MX = 1e5 + 1;
ll a;
int n, m, v[MX];
bool clc(int c) {
  ll s = 0;
  for (int i = 0; i < m; i++) {
    s += v[c];
    c = std::min(MX - 1, c + v[c]);
  }
  return s >= a;
}

int sol() {
  scanf("%d %d %lld", &n, &m, &a);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v[x] = x;
  }

  for (int i = 1; i < MX; i++)
    if (!v[i]) v[i] = v[i - 1];

  int s = 1, e = MX - 1, r = MX - 1;
  while (s <= e) {
    int p = (s + e) / 2;
    if (clc(p))
      r = std::min(r, p), e = p - 1;
    else
      s = p + 1;
  }
  return r;
}

int main() { printf("%d", sol()); }