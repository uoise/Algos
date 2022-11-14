#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using iip = pair<int, int>;
constexpr int MN = 1e9 + 1, MX = 0;
vector<int> vv;
vector<iip> tv;

void init(int nod, int beg, int end) {
  if (beg == end)
    tv[nod] = {vv[beg], vv[beg]};
  else {
    init(nod * 2, beg, (beg + end) / 2);
    init(nod * 2 + 1, (beg + end) / 2 + 1, end);
    tv[nod] = {min(tv[nod * 2].first, tv[nod * 2 + 1].first),
               max(tv[nod * 2].second, tv[nod * 2 + 1].second)};
  }
}

iip qry(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return {MN, MX};
  if (lft <= beg && rht >= end) return tv[nod];
  iip lp = qry(nod * 2, beg, (beg + end) / 2, lft, rht);
  iip rp = qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht);
  return {min(lp.first, rp.first), max(lp.second, rp.second)};
}

void sol(const int n, int m) {
  vv.assign(n, 0);
  for (auto& i : vv) cin >> i;

  int siz = log2(n);
  siz = 1 << (siz + 2);
  tv.assign(siz, {MN, MX});
  init(1, 0, n - 1);

  int l, r;
  while (m--) {
    cin >> l >> r;
    iip pr = qry(1, 0, n - 1, l - 1, r - 1);
    cout << pr.first << ' ' << pr.second << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  sol(n, m);
}
