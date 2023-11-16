#include <algorithm>
#include <cstdio>

struct vi {
  int v, i;
  bool operator<(const vi& o) const { return v == o.v ? i < o.i : v < o.v; }
};

constexpr int MX = 1e5 + 1, INF = 0x3f3f3f3f;
int n, vv[MX];
vi tv[MX * 4];
vi init(int nod, int beg, int end) {
  if (beg == end) return tv[nod] = {vv[beg], beg + 1};
  return tv[nod] = std::min(init(nod * 2, beg, (beg + end) / 2),
                            init(nod * 2 + 1, (beg + end) / 2 + 1, end));
}

vi qry(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || beg > rht) return {INF, INF};
  if (lft <= beg && end <= rht) return tv[nod];
  return std::min(qry(nod * 2, beg, (beg + end) / 2, lft, rht),
                  qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht));
}

vi update(int nod, int beg, int end, int idx, int val) {
  if (idx < beg || idx > end) return tv[nod];
  if (beg == end) return tv[nod] = {val, idx + 1};
  return tv[nod] =
             std::min(update(nod * 2, beg, (beg + end) / 2, idx, val),
                      update(nod * 2 + 1, (beg + end) / 2 + 1, end, idx, val));
}

int main() {
  int q, o, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  scanf("%d", &q);
  init(1, 0, n - 1);
  while (q--) {
    scanf("%d %d %d", &o, &x, &y);
    if (o == 1)
      update(1, 0, n - 1, x - 1, y);
    else
      printf("%d\n", qry(1, 0, n - 1, x - 1, y - 1).i);
  }
}