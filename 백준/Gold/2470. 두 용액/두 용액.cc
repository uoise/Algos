#include <algorithm>
#include <iostream>
using namespace std;

int n, rx, ry;
void sol(int *v) {
  int rr = 0, ll = n - 1, tr = 2e9;
  while (rr != ll) {
    if (abs(v[rr] + v[ll]) >= abs(tr)) {
      if (v[rr] + v[ll] > 0)
        ll--;
      else
        rr++;
    } else {
      rx = rr;
      ry = ll;
      tr = abs(v[rx] + v[ry]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  sol(v);
  cout << v[rx] << " " << v[ry];
}