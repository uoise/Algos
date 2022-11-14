#include <iostream>
using namespace std;
int res, cnt;
int recursion(const string& s, int l, int r) {
  cnt++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

void isPalindrome(const string& s) {
  cnt = 0;
  res = recursion(s, 0, s.size() - 1);
  cout << res << " " << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC;
  string s;
  cin >> TC;
  while (TC--) {
    cin >> s;
    isPalindrome(s);
  }
}