#include <iostream>
using namespace std;

void sol() {
  string s;
  cin >> s;
  if (s.size() == 1) {
    cout << 0 << ' ' << ((s[0] - '0') % 3 ? "NO" : "YES");
    return;
  }

  int n = 0, cnt = 1;
  for (const auto& c : s) n += (c - '0');

  while (n > 9) {
    int t = 0;
    while (n) {
      t += (n % 10);
      n /= 10;
    }
    n = t;
    ++cnt;
  }
  cout << cnt << ' ' << (n % 3 ? "NO" : "YES");
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sol();
}
