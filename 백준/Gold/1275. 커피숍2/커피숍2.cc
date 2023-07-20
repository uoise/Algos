#include <algorithm>
#include <cmath>
#include <cstdio>

using ci = const int;
using ll = long long;

constexpr int MX = 1e5 + 1;
int vv[MX];
ll sv[MX * 4];
ll init(ci& nod, ci& beg, ci& end) {
  if (beg == end) return sv[nod] = vv[beg];

  ci mid = (beg + end) / 2;
  return sv[nod] = init(nod * 2, beg, mid) + init(nod * 2 + 1, mid + 1, end);
}

ll update(ci& nod, ci& beg, ci& end, ci& idx, const ll& val) {
  if (idx < beg || idx > end) return sv[nod];
  if (beg == end) return sv[nod] = val;

  ci mid = (beg + end) / 2;
  return sv[nod] = update(nod * 2, beg, mid, idx, val) +
                   update(nod * 2 + 1, mid + 1, end, idx, val);
}

ll query(ci& nod, ci& beg, ci& end, ci& lft, ci& rht) {
  if (lft > end || rht < beg) return 0;
  if (lft <= beg && rht >= end) return sv[nod];
  ci mid = (beg + end) / 2;
  return query(nod * 2, beg, mid, lft, rht) +
         query(nod * 2 + 1, mid + 1, end, lft, rht);
}

int main() {
  int n, q, x, y, a, b;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  init(1, 0, n - 1);
  while (q--) {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    printf("%lld\n",
           query(1, 0, n - 1, std::min(x - 1, y - 1), std::max(x - 1, y - 1)));
    update(1, 0, n - 1, a - 1, vv[a - 1] = b);
  }
}