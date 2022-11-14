#include <iostream>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int tim[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
                 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
  int r = 0;
  for (int i = 0; i < s.length(); i++) r += tim[s.at(i) - 'A'];
  cout << r << '\n';
}
int main() { solve(); }