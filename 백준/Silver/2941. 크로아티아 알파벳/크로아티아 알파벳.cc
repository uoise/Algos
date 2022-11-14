#include <iostream>
using namespace std;

void solve() {
  string s;
  cin >> s;
  uint32_t i, r = 0, l = s.length();

  for (i = 0; i < l; i++) {
    ++r;
    if (s.at(i) == 'c' && i < l - 1) {
      if (s.at(i + 1) == '=' || s.at(i + 1) == '-') ++i;
    } else if (s.at(i) == 'd' && i < l - 1) {
      if (s.at(i + 1) == '-')
        ++i;
      else if (i < l - 2)
        if (s.at(i + 1) == 'z' && s.at(i + 2) == '=') i += 2;

    } else if ((s.at(i) == 'l' || s.at(i) == 'n') && i < l - 1) {
      if (s.at(i + 1) == 'j') ++i;

    } else if ((s.at(i) == 's' || s.at(i) == 'z') && i < l - 1) {
      if (s.at(i + 1) == '=') ++i;
    }
  }
  cout << r << '\n';
}

int main() { solve(); }