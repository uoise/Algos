#include <cmath>
#include <iostream>
using namespace std;

void solve() {
  int x1, x2, y1, y2, r1, r2, rm, rp;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  rm = (r1 - r2) > 0 ? r1 - r2 : r2 - r1;
  rp = r1 + r2;

  if (!d && !rm) {
    cout << -1 << '\n';
    return;
  }
  if (d > rp || d < rm || !d) {
    cout << 0 << '\n';
    return;
  }
  if (d == rp || d == rm) {
    cout << 1 << '\n';
    return;
  }
  if (d > rm && d < rp) {
    cout << 2 << '\n';
    return;
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  while (N--) solve();
}