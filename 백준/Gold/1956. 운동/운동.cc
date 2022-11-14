#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3F3F3F3F;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b, c, e, V, R = INF;

  cin >> V >> e;
  int grp[V + 1][V + 1];
  memset(grp, 0x3f, sizeof(grp));
  while (e--) {
    cin >> a >> b >> c;
    grp[a][b] = c;
  }

  // KWS
  for (int i = 1; i <= V; i++)
    for (int x = 1; x <= V; x++)
      for (int y = 1; y <= V; y++)
        if (x != y) grp[x][y] = min(grp[x][y], grp[x][i] + grp[i][y]);

  for (int x = 1; x <= V; x++)
    for (int y = x + 1; y <= V; y++)
      if (grp[x][y] != INF && grp[y][x] != INF)
        R = min(R, grp[x][y] + grp[y][x]);

  cout << (R == INF ? -1 : R);
}