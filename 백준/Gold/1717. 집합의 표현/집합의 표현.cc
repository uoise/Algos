#include <iostream>
using namespace std;
int vv[1000001];

int fnd(int cur) {
  if (cur == vv[cur]) return cur;
  return vv[cur] = fnd(vv[cur]);
}

void mks(int x, int y) {
  int xx = fnd(x), yy = fnd(y);
  if (xx > yy)
    vv[xx] = yy;
  else if (xx < yy)
    vv[yy] = xx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, o, a, b;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) vv[i] = i;
  while (m--) {
    cin >> o >> a >> b;
    if (!o)
      mks(a, b);
    else
      cout << (fnd(a) == fnd(b) ? "YES" : "NO") << '\n';
  }
}
