#include <iostream>
using namespace std;
int vv[5000001], res;

int fnd(int cur) {
  if (cur == vv[cur]) return cur;
  return vv[cur] = fnd(vv[cur]);
}

bool mks(int x, int y) {
  int xx = fnd(x), yy = fnd(y);
  if (!res && (xx == yy)) return true;
  if (xx > yy)
    vv[xx] = yy;
  else if (xx < yy)
    vv[yy] = xx;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;

  for (int i = 0; i <= n; i++) vv[i] = i;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    if (mks(a, b)) res = i;
  }
  cout << res;
}
