#include <cmath>
#include <iostream>
using namespace std;

int nv[10];
int sol(int n) {
  while (n) {
    nv[n % 10]++;
    n /= 10;
  }
  nv[6] = ceil(float(nv[6] + nv[9]) / 2);
  nv[9] = 0;
  int mxx = -1;
  for (const int& i : nv) mxx = max(mxx, i);
  return mxx;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n);
}