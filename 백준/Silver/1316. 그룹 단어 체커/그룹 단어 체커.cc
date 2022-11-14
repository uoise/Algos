#include <iostream>
using namespace std;

bool solve() {
  string s;
  cin >> s;
  uint32_t l = s.length();
  if (l == 1) return true;

  bool alpha[26];
  uint32_t i, cur = s.at(0) - 'a';
  for (i = 0; i < 26; i++) alpha[i] = true;
  alpha[s.at(0) - 'a'] = false;
  
  for (i = 1; i < l; i++) {
    if (alpha[s.at(i) - 'a'])
      alpha[s.at(i) - 'a'] = false;
    else if (!alpha[s.at(i) - 'a'] && s.at(i) != s.at(i - 1))
      return false;
  }
  return true;
}

int main() {
  uint32_t T, r = 0;
  cin >> T;
  for (uint32_t testCase = 0; testCase < T; testCase++) {
    r += (uint32_t)solve();
  }
  cout << r << '\n';
}