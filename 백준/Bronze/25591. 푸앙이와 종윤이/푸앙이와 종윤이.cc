#include <iostream>
using namespace std;

void solution() {
  int x, y;
  cin >> x >> y;
  int a = 100 - x, b = 100 - y;
  int c = 100 - (a + b);
  int d = a * b;
  int q = d / 100, r = d % 100;
  cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << '\n';
  cout << c + q << " " << r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  solution();
}
