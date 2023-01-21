#include <algorithm>
#include <iostream>

using namespace std;
struct nyks {
  string n;
  int k, y, s;
  bool operator<(const nyks& x) const {
    if (k != x.k)
      return k > x.k;
    else if (y != x.y)
      return y < x.y;
    else if (s != x.s)
      return s > x.s;
    else
      return n < x.n;
  }
};

nyks v[100001];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i].n >> v[i].k >> v[i].y >> v[i].s;
  sort(v, v + n);
  for (int i = 0; i < n; i++) cout << v[i].n << '\n';
}