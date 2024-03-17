#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s[9];
bool b[9];
int n, r = 0x3f3f3f3f;
string clc(const string& x, const string& y) {
  int xl = x.length(), yl = y.length();
  for (int k = min(xl, yl); k; k--)
    if (x.substr(xl - k) == y.substr(0, k)) return x.substr(0, xl - k) + y;
  return "";
}

void btr(int d, string c) {
  if (!d) {
    r = min(r, (int)c.length());
    return;
  }

  for (int i = 0; i < n; i++) {
    if (b[i]) continue;
    string a = clc(c, s[i]);
    if (a.empty()) continue;
    b[i] = 1;
    btr(d - 1, a);
    b[i] = 0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    b[i] = 1;
    btr(n - 1, s[i]);
    b[i] = 0;
  }
  cout << r;
}