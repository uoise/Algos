#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> vv;
void inp() {
  cin >> n;
  vv.resize(n);
  for (auto& s : vv) {
    cin >> s;
    reverse(s.begin(), s.end());
  }
}

int sol() {
  int sz = vv[0].size();
  while (--sz) {
    for (auto& s : vv) s.pop_back();
    sort(vv.begin(), vv.end());
    for (int i = 1; i < n; i++) {
      if (vv[i] == vv[i - 1]) return sz + 1;
    }
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  inp();
  cout << sol();
}