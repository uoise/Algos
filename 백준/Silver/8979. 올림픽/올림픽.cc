#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct gsb {
  int v, g, s, b, o;
  gsb() : v(0), g(0), s(0), b(0), o(0) {}
  bool iss(const gsb& a) { return (g == a.g) && (s == a.s) && (b == a.b); }
};

bool operator<(const gsb& a, const gsb& b) {
  if (a.g != b.g) return a.g > b.g;
  if (a.s != b.s) return a.s > b.s;
  return a.b > b.b;
}

int sol(int n, int k) {
  vector<gsb> vv(n);
  for (int i = 0; i < n; i++) cin >> vv[i].v >> vv[i].g >> vv[i].s >> vv[i].b;
  sort(vv.begin(), vv.end());
  int ord = 1, lst = 0;

  for (int i = 1; i < n; i++) {
    if (vv[lst].iss(vv[i])) vv[i].o = ord;
    else {
      vv[i].o = ++ord;
      lst = i;
    }
  }
  for (int i = 0; i < n; i++)
    if (vv[i].v == k) return vv[i].o;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  cout << sol(n, k);
}