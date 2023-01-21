#include <algorithm>
#include <iostream>

using namespace std;
struct nyks {
  string n;
  int k, y, s;
  bool operator<(const nyks& x) const {
    return k != x.k ? k > x.k
                    : (y != x.y ? y < x.y : (s != x.s ? s > x.s : n < x.n));
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