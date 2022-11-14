#include <iostream>
using namespace std;
void solve() {
  int a, b, c, m;
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c;
  if ((a == 0) && (b == 0) & (c == 0)) return;
  m = a;
  if (m < b) m = b;
  if (m < c) m = c;
  if (2 * (m * m) == (a * a + b * b + c * c))
    cout << "right" << '\n';
  else
    cout << "wrong" << '\n';
  solve();
}

int main() { solve(); }