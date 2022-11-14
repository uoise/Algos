#include <algorithm>
#include <iostream>

using namespace std;

int sol(const int n) {
  pair<int, int> vv[n];
  for (auto& p : vv) cin >> p.first >> p.second;
  sort(vv, vv + n);
  int beg = 2e9, end = -2e9, res = 0;
  for (const auto& p : vv) {
    if (p.first > end) {
      beg = p.first;
      end = p.second;
      res += (end - beg);
    } else if (p.second > end) {
      res += (p.second - end);
      end = p.second;
    }
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n);
}