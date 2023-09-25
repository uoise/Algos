#include <algorithm>
#include <cstdio>

using ll = long long;

ll v[1 << 21];
void mod(int nod, int beg, int end, int idx, int val) {
  if (idx < beg || idx > end) return;
  if (beg == end) {
    v[nod] = val;
    return;
  }
  mod(nod * 2, beg, (beg + end) / 2, idx, val);
  mod(nod * 2 + 1, (beg + end) / 2 + 1, end, idx, val);
  v[nod] = v[nod * 2] + v[nod * 2 + 1];
}

ll qry(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return 0;
  if (lft <= beg && rht >= end) return v[nod];
  return qry(nod * 2, beg, (beg + end) / 2, lft, rht) +
         qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht);
}

int main() {
  int n, m, o, s, e;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %d", &o, &s, &e);
    if (!o) printf("%lld\n", qry(1, 0, n - 1, std::min(s - 1, e - 1), std::max(s - 1, e - 1)));
    else mod(1, 0, n - 1, s - 1, e);
  }
}