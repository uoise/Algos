#include <iostream>
using namespace std;
inline int getLenPow(const int x1, const int x2, const int y1, const int y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
void solve() {
  int x1, x2, y1, y2, N, i, r = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> N;
  int xx[N], yy[N], rr[N];
  for (i = 0; i < N; i++) {
    cin >> xx[i] >> yy[i] >> rr[i];
    rr[i] = rr[i] * rr[i];
  }

  for (i = 0; i < N; i++)
    if (((rr[i] > getLenPow(xx[i], x1, yy[i], y1)) ^
         (rr[i] > getLenPow(xx[i], x2, yy[i], y2))))
      r++;

  cout << r << '\n';
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
}