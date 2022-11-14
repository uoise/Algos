#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> lv;

void sol(const int n) {
  long long cnt = 0, res = 0;
  for (auto& i : lv) cin >> i;
  sort(lv.begin(), lv.end());

  for (const auto& i : lv) {
    if (cnt == 0) res = i;
    (res == i) ? cnt++ : cnt--;
  }
  cnt = 0;
  for (const auto& i : lv)
    if (res == i) cnt++;

  if (cnt > n / 2)
    cout << res << '\n';
  else
    cout << "SYJKGW\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int TC, n;
  cin >> TC;
  while (TC--) {
    cin >> n;
    lv.resize(n);
    sol(n);
    lv.clear();
  }
}