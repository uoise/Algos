#include <algorithm>
#include <cstdio>

int a[100001], v[1 << 21];
int init(int nod, int beg, int end) {
  return v[nod] = (beg == end) ? a[beg]
         : std::min(init(nod * 2, beg, (beg + end) / 2),
                    init(nod * 2 + 1, (beg + end) / 2 + 1, end));
}

int mod(int nod, int beg, int end, int idx, int val) {
  if (idx < beg || idx > end) return v[nod];
  return v[nod] = (beg == end) ? val
         : std::min(mod(nod * 2, beg, (beg + end) / 2, idx, val),
                    mod(nod * 2 + 1, (beg + end) / 2 + 1, end, idx, val));
}

int qry(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return 1e9 + 1;
  return (lft <= beg && rht >= end) ? v[nod]
         : std::min(qry(nod * 2, beg, (beg + end) / 2, lft, rht),
                    qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht));
}

int main() {
  int n, m, o, s, e;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  init(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d %d", &o, &s, &e);
    if (o == 1) mod(1, 1, n, s, e);
    else printf("%d\n", qry(1, 1, n, s, e));
  }
}