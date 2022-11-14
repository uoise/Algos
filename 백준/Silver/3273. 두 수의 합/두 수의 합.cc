#include <algorithm>
#include <iostream>
using namespace std;

int n, x;
int sol(int *v) {
  int rr = 1, ll = n, cnt = 0;
  while (rr != ll) {
    if (v[rr] + v[ll] == x) {
      cnt++;
      rr++;
    } else if (v[rr] + v[ll] < x) {
      rr++;
    } else {
      ll--;
    }
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  int v[n + 1];
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v + 1, v + n + 1);
  cin >> x;
  cout << sol(v);
}