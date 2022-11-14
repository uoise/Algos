#include <algorithm>
#include <iostream>

using namespace std;

int n;
int sol() {
  int vv[n], beg = 0, end = 0, cnt = 4;
  for (auto& i : vv) cin >> i;
  sort(vv, vv + n);
  while (beg < n && end < n) {
    if (vv[end] - vv[beg] > 4)
      beg++;
    else {
      if (end > beg) cnt = min(cnt, 4 - (end - beg));
      end++;
    }
  }
  return cnt;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}