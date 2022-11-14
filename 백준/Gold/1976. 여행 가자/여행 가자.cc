#include <iostream>
using namespace std;
int vv[201], rr[1001];

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
  int n, m, o;
  bool res = true;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) vv[i] = i;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> o;
      if (o) mks(i, j);
    }
  }

  for (int i = 0; i < m; i++) cin >> rr[i];
  for (int i = 1; i < m; i++)
    if (fnd(rr[i - 1]) != fnd(rr[i])) {
      res = false;
      break;
    }
  cout << (res ? "YES" : "NO");
}
