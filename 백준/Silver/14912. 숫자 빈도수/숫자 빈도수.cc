#include <iostream>

using namespace std;

int sol(const int n, const int d) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int x = i;
    while (x) {
      if (d == x % 10) res++;
      x /= 10;
    }
  }
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  cout << sol(n, d);
}