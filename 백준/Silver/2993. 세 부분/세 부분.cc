#include <algorithm>
#include <iostream>

using namespace std;

string sol(string n) {
  int siz = n.size();
  string r(siz, 'z'), s;

  for (int i = 0; i < siz - 2; i++) {
    for (int j = i + 1; j < siz - 1; j++) {
      s = n;
      reverse(s.begin(), s.begin() + i + 1);
      reverse(s.begin() + i + 1, s.begin() + j + 1);
      reverse(s.begin() + j + 1, s.end());
      r = min(r, s);
    }
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  cout << sol(s);
}
