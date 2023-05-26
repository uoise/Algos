#include <iostream>

using namespace std;

string s;
bool r;
int sol() {
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) return s.length();
    if (s[i] != s[i + 1]) r = 1;
  }
  return r ? s.length() - 1 : -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  cout << sol();
}