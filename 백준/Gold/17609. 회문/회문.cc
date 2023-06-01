#include <algorithm>
#include <iostream>

using namespace std;

string s;
int sol(int l, int r, const bool t) {
  while (l < r)
    if (s[l++] != s[r--])
      return t ? 1 : min(sol(l - 1, r, 1), sol(l, r + 1, 1)) + 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    cout << sol(0, s.length() - 1, 0) << '\n';
  }
}