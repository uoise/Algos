#include <algorithm>
#include <iostream>

using namespace std;

string t;
bool dfs(const string& c) {
  if (c.length() == t.length()) return t.compare(c) == 0;

  if (c[c.length() - 1] == 'A')
    if (dfs(c.substr(0, c.length() - 1))) return true;
    
  if (c[0] != 'B') return false;
  string n = c.substr(1, c.length() - 1);
  reverse(n.begin(), n.end());
  return dfs(n);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> t >> s;
  cout << dfs(s) ? 1 : 0;
}