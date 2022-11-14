#include <iostream>
using namespace std;
int pv[1001];
int fnd(const int x) {
  if (x == pv[x]) return x;
  return pv[x] = fnd(pv[x]);
}
bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  pv[y] = x;
  return x != y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;
  int r = n;
  for (int i = 1; i <= n; i++) pv[i] = i;
  while (m--) {
    cin >> a >> b;
    r -= mks(a, b);
  }
  cout << r;
}
