#include <iostream>
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  a = (a % 10) * 100 + (a % 100 - a % 10) + (a / 100);
  b = (b % 10) * 100 + (b % 100 - b % 10) + (b / 100);
  if (a > b)
    cout << a << '\n';
  else
    cout << b << '\n';
}

int main() { solve(); }