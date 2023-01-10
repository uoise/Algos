#include <iostream>
using namespace std;
int n, r;
string s;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (1) {
    cin >> s;
    if (s[0] == '0') break;
    r = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] != s[s.size() - i - 1]) r = 1;
    cout << (r ? "no" : "yes") << '\n';
  }
}