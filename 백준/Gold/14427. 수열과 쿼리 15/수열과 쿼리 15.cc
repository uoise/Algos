#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;
using iip = pair<int, int>;
constexpr int INF = 2e9;
vector<iip> tv;
int vv[100000], n;
iip cmp(const iip& x, const iip& y) {
  if (x.first == y.first) return x.second < y.second ? x : y;
  return x.first < y.first ? x : y;
}

void init(int nod, int beg, int end) {
  if (beg == end) {
    tv[nod] = {vv[beg], beg};
  } else {
    int mid = (beg + end) / 2, chd = nod * 2;
    init(chd, beg, mid);
    init(chd + 1, mid + 1, end);
    tv[nod] = cmp(tv[chd], tv[chd + 1]);
  }
}

void update(int nod, int beg, int end, int idx, int val) {
  if (idx < beg || idx > end) return;
  if (beg == end) {
    tv[nod].first = val;
    vv[idx] = val;
  } else {
    int mid = (beg + end) / 2, chd = nod * 2;
    update(chd, beg, mid, idx, val);
    update(chd + 1, mid + 1, end, idx, val);
    tv[nod] = cmp(tv[chd], tv[chd + 1]);
  }
}

void inp() {
  int h;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  h = (int)ceil(log2(n));
  h = 1 << (h + 1);
  tv.reserve(h);
  init(1, 0, n - 1);
}

void solve() {
  int m, q, p, v;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &q);
    if (q & 1) {
      scanf("%d %d", &p, &v);
      update(1, 0, n - 1, p - 1, v);
    } else {
      printf("%d\n", tv[1].second + 1);
    }
  }
}

int main() {
  inp();
  solve();
}