#include <iostream>
using namespace std;
constexpr int MX = 100001;
int n;
int iv[MX], pv[MX], ii[MX];

void sol(int ib, int ie, int pb, int pe) {
  if (ib > ie || pb > pe) return;
  int idx = ii[pv[pe]];
  int gap = idx - ib;
  cout << iv[idx] << " ";
  sol(ib, idx - 1, pb, pb + gap - 1);
  sol(idx + 1, ie, pb + gap, pe - 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> iv[i];
    ii[iv[i]] = i;
  }
  for (int i = 1; i <= n; i++) cin >> pv[i];
  sol(1, n, 1, n);
}
