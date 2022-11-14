#include <iostream>

using namespace std;
using ll = long long;
constexpr ll lo = 1e9 + 7;

ll pow(int p) {
  if (!p) return 1;
  if (p == 1) return 2;
  ll r = pow(p / 2) % lo;
  r = r * r % lo;
  return (p & 1 ? r * 2 % lo : r);
}

int sol(int n) {
  ll c, k, r = 0;
  while (n--) {
    cin >> c >> k;
    c *= k * pow(k - 1) % lo;
    r = (r + c) % lo;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n);
}