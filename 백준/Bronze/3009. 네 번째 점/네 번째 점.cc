#include <iostream>
using namespace std;
void solve() {
  int x[3], y[3], xx, yy = 0;
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> x[0] >> y[0];
  cin >> x[1] >> y[1];
  cin >> x[2] >> y[2];
  if (x[0] == x[1])
    xx = 2;
  else if (x[0] == x[2])
    xx = 1;
  else
    xx = 0;
  if (y[0] == y[1])
    yy = 2;
  else if (y[0] == y[2])
    yy = 1;
  else
    yy = 0;
  cout << x[xx] << " " << y[yy] << '\n';
}
int main() { solve(); }