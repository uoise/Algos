#include <iostream>
#include <map>
#include <string>
using namespace std;
string s;
map<string, float> m;
int c;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  while (getline(cin, s)) ++m[s], ++c;
  cout << fixed;
  cout.precision(4);
  for (auto [k, v] : m) cout << k << ' ' << v / c * 100 << '\n';
}