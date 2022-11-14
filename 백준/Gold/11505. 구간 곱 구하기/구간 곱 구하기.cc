#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
constexpr ll lmt = 1000000007;
vector<ll> st;

void init(const vector<ll>& nv, int nod, int beg, int end) {
  if (beg == end)
    st[nod] = nv[beg];
  else {
    init(nv, nod * 2, beg, (beg + end) / 2);
    init(nv, nod * 2 + 1, (beg + end) / 2 + 1, end);
    st[nod] = (st[nod * 2] * st[nod * 2 + 1]) % lmt;
  }
}

void update(int nod, int beg, int end, int idx, ll val) {
  if (idx < beg || idx > end) return;
  if (beg == end)
    st[nod] = val;
  else {
    update(nod * 2, beg, (beg + end) / 2, idx, val);
    update(nod * 2 + 1, (beg + end) / 2 + 1, end, idx, val);
    st[nod] = (st[nod * 2] * st[nod * 2 + 1]) % lmt;
  }
}

ll query(int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return 1;
  if (lft <= beg && rht >= end) return st[nod];
  ll lv = query(nod * 2, beg, (beg + end) / 2, lft, rht);
  ll rv = query(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht);
  return (lv * rv) % lmt;
}

void sol(const int n, int m) {
  int siz = ceil(log2(n));
  siz = 1 << (siz + 1);
  st.assign(siz, 1);
  vector<ll> nv(n);
  for (auto& i : nv) cin >> i;
  init(nv, 1, 0, n - 1);

  int a, b, c;
  while (m--) {
    cin >> a >> b >> c;
    if (a == 1)
      update(1, 0, n - 1, b - 1, c);
    else
      cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  m += k;
  sol(n, m);
}