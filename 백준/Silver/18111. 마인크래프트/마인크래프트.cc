#include <iostream>
#include <vector>

using namespace std;

void sol() {
  int n, m, b;
  cin >> n >> m >> b;
  n *= m;
  vector<int> vv(n);
  m = b;
  int mn = 2e9, mx = 0;
  for (auto& i : vv) {
    cin >> i;
    mn = min(mn, i), mx = max(mx, i);
    m += i;
  }

  int rem = 2e9, reh;
  for (int h = mn; h <= mx && (h * n <= m); h++) {
    int crt = 0;
    for (int i = 0; i < n; i++) {
      int cur = h - vv[i];
      crt += (cur < 0 ? cur * -2 : cur);
    }
    if (rem >= crt) {
      rem = crt;
      reh = h;
    }
  }
  cout << rem << ' ' << reh;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sol();
}