#include <iostream>

using namespace std;

int pow(int p) {
  if (p <= 1) return 1;
  int r = pow(p / 2);
  return r * r;
}

int sol(int n) {
  int c, k, r = 0;
  while (n--) {
    cin >> c >> k;
    c *= k * pow(k - 1);
    r += c;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n);
}
