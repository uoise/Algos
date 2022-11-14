#include <iostream>
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  if (x == 0 && y == 0)
    return;
  else if ((x > y) && (x % y == 0))
    cout << "multiple" << '\n';
  else if ((x < y) && (y % x == 0))
    cout << "factor" << '\n';
  else
    cout << "neither" << '\n';
  solve();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}