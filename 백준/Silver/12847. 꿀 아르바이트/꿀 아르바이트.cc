#include <iostream>

using namespace std;
using ll = long long;
int n, m;
ll sol() {
  ll vv[n], rv[n], res = 0;
  for (auto& i : vv) cin >> i;
  rv[0] = vv[0];
  for (int i = 1; i < n; i++) {
    rv[i] = rv[i - 1] + vv[i];
    if (i >= m) rv[i] -= vv[i - m];
    res = max(rv[i], res);
  }
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  cout << sol();
}