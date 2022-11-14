#include <algorithm>
#include <iostream>

using namespace std;

int n;

int sol() {
  int aa[n], bb[n], res = 0;
  for (auto& i : aa) cin >> i;
  for (auto& i : bb) cin >> i;
  sort(aa, aa + n);
  sort(bb, bb + n);
  for (int i = 0; i < n; i++) res += (aa[n - 1 - i] * bb[i]);
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}