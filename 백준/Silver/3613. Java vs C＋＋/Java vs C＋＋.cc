#include <iostream>
using namespace std;
string solve(string s) {
  string res = "Error!\n";

  bool upr = false, jv = false, cc = false;
  if (s[0] == '_' || s[s.size() - 1] == '_' || (s[0] >= 'A' && s[0] <= 'Z'))
    return res;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] < 'a' || s[i] > 'z') {
      if (s[i] == '_') cc = true;
      if (s[i] >= 'A' && s[i] <= 'Z') jv = true;
    }
  }
  if (jv && cc) return res;
  res = "";
  for (int i = 0; i < s.size(); i++) {
    if (upr) {
      if (s[i] == '_') return "Error!\n";
      res += s[i] - 32;
      upr = false;
    } else if (s[i] == '_')
      upr = true;
    else if (s[i] >= 'A' && s[i] <= 'Z') {
      res += '_';
      res += s[i] + 32;
    } else
      res += s[i];
  }
  res += '\n';
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  cout << solve(s);
}