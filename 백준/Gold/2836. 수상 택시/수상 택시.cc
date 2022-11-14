#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

ll sol() {
  int n, m, c = 0;
  ll b, e, r = 0;
  cin >> n >> m;
  pair<int, int> vv[n];
  for (int i = 0; i < n; i++) {
    cin >> b >> e;
    if (b > e) vv[c++] = {e, b};
  }
  if (!c) return m;

  sort(vv, vv + c);
  b = vv[0].second, e = vv[0].first;
  for (int i = 1; i < c; i++) {
    if (vv[i].first > b) {
      r += ((b - e) * 2);
      b = vv[i].second, e = vv[i].first;
    } else {
      b = b > vv[i].second ? b : vv[i].second;
      e = e < vv[i].first ? e : vv[i].first;
    }
  }

  return r + (b - e) * 2 + m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << sol();
}