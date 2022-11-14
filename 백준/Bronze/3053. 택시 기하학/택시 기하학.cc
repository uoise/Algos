#include <cmath>
#include <iostream>
using namespace std;

void solve() {
  double r;
  cin >> r;
  cout.setf(ios::fixed);
  cout.precision(6);
  cout << M_PI * r * r << '\n';
  cout << r * r * 2 << '\n';
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}