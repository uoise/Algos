#include <iostream>
using namespace std;
using ll = long long;

ll sol(const int n) {
  if (n < 1e1) return n;
  if (n < 1e2) return (n - 9) * 2 + 9;
  if (n < 1e3) return (n - 99) * 3 + 189;
  if (n < 1e4) return (n - 999) * 4 + 2889;
  if (n < 1e5) return (n - 9999) * 5 + 38889;
  if (n < 1e6) return (n - 99999) * 6 + 488889;
  if (n < 1e7) return (n - 999999) * 7 + 5888889;
  if (n < 1e8) return (n - 9999999) * 8 + 68888889;
  return (n - 99999999) * 9 + 788888889;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n);
}
