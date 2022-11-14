#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using iar = vector<int>;
using iir = vector<iar>;
iar cv(4, 0);
int n;

void clc(const iir& s, iir& d) {
  const int siz = s.size();
  for (int y = 0; y < siz; y += 2)
    for (int x = 0; x < siz; x += 2) {
      cv[0] = s[y][x], cv[1] = s[y][x + 1], cv[2] = s[y + 1][x], cv[3] = s[y + 1][x + 1];
      sort(cv.begin(), cv.end());
      d[y / 2][x / 2] = cv[2];
    }
}

int sol() {
  vector<iir> vvv;
  for (int i = 1; i <= n; i *= 2) vvv.push_back(iir(i, iar(i)));
  int sz = vvv.size() - 1;
  for (auto& v : vvv[sz])
    for (auto& i : v) cin >> i;

  for (int i = sz; i; i--) clc(vvv[i], vvv[i - 1]);
  return vvv[0][0][0];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}