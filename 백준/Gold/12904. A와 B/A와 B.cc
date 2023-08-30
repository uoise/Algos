#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string t;
int r;
void sol(const string& x) {
  if (r) return;
  if (x.length() < t.length()) return;
  if (x.length() == t.length()) {
    if (x.compare(t) == 0) r = 1;
    return;
  }

  string y = x.substr(0, x.length() - 1);
  if (x[x.length() - 1] == 'B') std::reverse(y.begin(), y.end());
  sol(y);
}

int main() {
  string s;
  cin.tie(0)->sync_with_stdio(0);
  cin >> t >> s;
  sol(s);
  cout << r;
}