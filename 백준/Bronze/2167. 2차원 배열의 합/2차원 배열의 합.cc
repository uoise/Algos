#include <iostream>
using namespace std;

int vv[301][301];

void sol() {
  int n, m, k, bx, ex, by, ey;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> vv[i][j];
      vv[i][j] += (vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1]);
    }
  }

  cin >> k;
  while (k--) {
    cin >> bx >> by >> ex >> ey;
    cout << vv[ex][ey] - vv[bx - 1][ey] - vv[ex][by - 1] + vv[bx - 1][by - 1]
         << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sol();
}
