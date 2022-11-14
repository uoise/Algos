#include <iostream>
using namespace std;
inline int getLenPow(const int x1, const int x2, const int y1, const int y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
void solve() {
  int W, H, X, Y, P, x, y, r = 0;
  cin >> W >> H >> X >> Y >> P;
  int R = H / 2;
  while (P--) {
    cin >> x >> y;
    if ((x >= X && x <= X + W) && (y >= Y && y <= Y + H))
      r++;
    else if (getLenPow(x, X, y, Y + R) <= (R * R) ||
             getLenPow(x, X + W, y, Y + R) <= (R * R))
      r++;
  }
  cout << r << '\n';
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}