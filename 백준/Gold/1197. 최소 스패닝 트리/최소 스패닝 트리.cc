#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct bec {
  int b, e, c;
  bec(int b = 0, int e = 0, ll c = 0) : b(b), e(e), c(c) {}
};
bool operator<(const bec& x, const bec& y) { return x.c < y.c; }
vector<bec> egv;
vector<int> vv;

int fnd(const int x) {
  if (vv[x] < 0) return x;
  return vv[x] = fnd(vv[x]);
}
void mks(const int x, const int y) {
  const int xx = fnd(x), yy = fnd(y);
  if (xx == yy) return;
  if (xx < yy) {
    vv[xx] += vv[yy];
    vv[yy] = xx;
  } else {
    vv[yy] += vv[xx];
    vv[xx] = yy;
  }
}

ll mst() {
  ll r = 0;
  for (const auto& cur : egv) {
    const int bb = fnd(cur.b), ee = fnd(cur.e);
    if (bb != ee) {
      mks(bb, ee);
      r += cur.c;
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int V, E, x, y, z;
  cin >> V >> E;
  egv.resize(E + 1);
  vv.assign(V + 1, -1);
  for (int i = 0; i < E; i++) {
    cin >> x >> y >> z;
    egv[i] = {x, y, z};
  }
  sort(egv.begin(), egv.end());
  cout << mst();
}
