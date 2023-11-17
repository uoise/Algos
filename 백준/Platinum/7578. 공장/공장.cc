#include <cstdio>

constexpr int MX = 5e5 + 1;
int n, iv[MX * 2], vv[MX * 2];
long long tv[MX * 4];
long long qry(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return 0;
  if (lft <= beg && rht >= end) return tv[nod];
  return qry(nod * 2, beg, (beg + end) / 2, lft, rht) +
         qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht);
}

void mod(int nod, int beg, int end, int idx) {
  if (idx < beg || idx > end) return;
  ++tv[nod];
  if (beg == end) return;
  mod(nod * 2, beg, (beg + end) / 2, idx);
  mod(nod * 2 + 1, (beg + end) / 2 + 1, end, idx);
}

int main() {
  int x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    iv[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    vv[iv[x]] = i;
  }
  long long r = 0;
  for (int i = 1; i <= n; i++) {
    x = vv[i];
    r += qry(1, 1, n, x + 1, n);
    mod(1, 1, n, x);
  }
  printf("%lld", r);
}