#include <algorithm>
#include <iostream>

using namespace std;

int n;

int sol() {
  int wv[n], res = 0;
  for (auto& i : wv) cin >> i;
  sort(wv, wv + n);
  for (int i = 0; i < n; i++) res = max(res, wv[i] * (n - i));
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}