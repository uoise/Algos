#include <algorithm>
#include <cstdio>
#include <set>

using ll = long long;
using namespace std;

constexpr int xx[] = {0, 1, 0, -1, 0}, yy[] = {0, 0, 1, 0, -1};
set<pair<ll, ll>> s, p;
int len(ll x, ll y) { return min(6LL, abs(x) + abs(y)); }
int sol() {
  int n, k;
  scanf("%d %d", &n, &k);
  while (n--) {
    ll x, y;
    scanf("%lld %lld", &x, &y);
    s.insert({x, y});
  }
  ll ex, ey;
  scanf("%lld %lld", &ex, &ey);

  int r = len(ex, ey);
  for (const auto [x, y] : s) {
    r = min(r, len(ex - x, ey - y) + 2);
    p.insert({ex - x, ey - y});
  }

  for (const auto [x, y] : s)
    for (int d = 0; d < 5; d++)
      if (p.count({x + xx[d], y + yy[d]})) r = min(r, d ? 5 : 4);

  return r > k ? -1 : r;
}

int main() { printf("%d", sol()); }