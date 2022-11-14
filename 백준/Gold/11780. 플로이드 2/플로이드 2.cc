#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
constexpr int INF = 0x3F3F3F3F, MX = 101;
int dst[MX][MX], rt[MX][MX], N;
vector<int> rr;
void fws() {
  for (int i = 1; i <= N; i++)
    for (int x = 1; x <= N; x++)
      for (int y = 1; y <= N; y++)
        if (x != y && dst[x][y] > dst[x][i] + dst[i][y]) {
          dst[x][y] = dst[x][i] + dst[i][y];
          rt[x][y] = i;
        }
}
void fmd(const int beg, const int end) {
  if (rt[beg][end] != INF) {
    fmd(beg, rt[beg][end]);
    rr.push_back(rt[beg][end]);
    fmd(rt[beg][end], end);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m, a, b, c;
  cin >> N >> m;

  memset(dst, 0x3F, sizeof(dst));
  memset(rt, 0x3F, sizeof(rt));

  while (m--) {
    cin >> a >> b >> c;
    if (dst[a][b] > c) dst[a][b] = c;
  }

  fws();

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << ((dst[i][j] == INF) ? 0 : dst[i][j]) << " ";
    cout << '\n';
  }

  // trb

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j || dst[i][j] == INF) {
        cout << "0\n";
      } else {
        rr.clear();
        rr.push_back(i);
        fmd(i, j);
        rr.push_back(j);
        cout << rr.size() << " ";
        for (const auto& i : rr) cout << i << " ";
        cout << '\n';
      }
    }
  }
}