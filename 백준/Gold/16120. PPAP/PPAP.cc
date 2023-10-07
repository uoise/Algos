#include <iostream>
#include <string>

using namespace std;
int stk;
string s;
bool sol() {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'P') {
      ++stk;
      continue;
    }

    if (stk >= 2 && s[i + 1] == 'P') {
      --stk, ++i;
      continue;
    }

    return 0;
  }

  return stk == 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  cout << (sol() ? "PPAP" : "NP");
}