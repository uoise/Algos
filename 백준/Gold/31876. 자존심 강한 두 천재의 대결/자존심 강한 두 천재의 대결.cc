#include <iostream>

using namespace std;

int sol() {
  int u, v;
  string a, b;
  cin >> u >> v >> a >> b;
  int n = a.length();

  if (u == v) {
    for (int i = 0; i < n; i++) if (a[i] != b[i]) return a[i] > b[i] ? 1 : 2;
    return 0;
  }

  if (n > 24) return u > v ? 1 : 2;

  long long rs = 0, as = 0, rt = 1, at = 1;
  for (int i = n - 1; i >= 0; i--) {
    rs += rt * (a[i] - '0'), as += at * (b[i] - '0');
    rt *= u, at *= v;
  }
  return rs == as ? 0 : rs > as ? 1 : 2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int r = sol();
  cout << (r ? (r == 1 ? "ras" : "auq") : "rasauq");
}