#include <iostream>

using namespace std;

int T;
string c;
bool vld(const int& s, int e) {
  if (e == s) return true;
  int m = s;
  while (m < e) if (c[m++] == c[e--]) return false;
  return vld(s, m - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> c;
    cout << (vld(0, c.length() - 1) ? "YES" : "NO") << '\n';
  }
}