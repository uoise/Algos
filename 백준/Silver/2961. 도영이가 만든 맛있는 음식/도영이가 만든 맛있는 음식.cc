#include <iostream>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, a, b;
  cin >> n;
  pair<int, int> vv[n];
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vv[i] = {a, b};
  }
  ll set = 0, min = 9e14;
  for (int i = 0; i < n; i++) set |= (1 << i); 
  for (ll subset = set; subset; subset = ((subset - 1) & set)) { 
    ll mul = 1, add = 0;
    for (int i = 0; i < n; i++) {
      if (subset & (1 << i)) mul *= vv[i].first, add += vv[i].second;
    }
    if (min > abs(mul - add)) min = abs(mul - add);
  }
  cout << min;
}