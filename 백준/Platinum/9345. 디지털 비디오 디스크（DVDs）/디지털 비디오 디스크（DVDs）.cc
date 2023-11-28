#include <algorithm>
#include <cstdio>

using pi = std::pair<int, int>;
constexpr int MX = 1e5 + 1;

int vv[MX];
pi tv[MX * 4];
pi cmp(const pi& x, const pi& y) {
  return {std::min(x.first, y.first), std::max(x.second, y.second)};
}

pi init(int nod, int beg, int end) {
  if (beg == end) return tv[nod] = {beg, beg};
  init(nod * 2, beg, (beg + end) / 2);
  init(nod * 2 + 1, (beg + end) / 2 + 1, end);
  return tv[nod] = cmp(tv[nod * 2], tv[nod * 2 + 1]);
}

pi qry(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || beg > rht) return {MX, -MX};
  if (lft <= beg && end <= rht) return tv[nod];
  return cmp(qry(nod * 2, beg, (beg + end) / 2, lft, rht),
             qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht));
}

pi mod(int nod, int beg, int end, int idx, int val) {
  if (idx < beg || idx > end) return tv[nod];
  if (beg == end) return tv[nod] = {val, val};
  return tv[nod] = cmp(mod(nod * 2, beg, (beg + end) / 2, idx, val),
                       mod(nod * 2 + 1, (beg + end) / 2 + 1, end, idx, val));
}

void sol() {
  int n, k, q, a, b;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) vv[i] = i;
  init(1, 0, n - 1);
  while (k--) {
    scanf("%d %d %d", &q, &a, &b);
    if (!q) {
      mod(1, 0, n - 1, vv[a], b), mod(1, 0, n - 1, vv[b], a);
      std::swap(vv[a], vv[b]);
    } else {
      auto [l, r] = qry(1, 0, n - 1, a, b);
      printf("%s\n", l == a && r == b ? "YES" : "NO");
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}