#include <iostream>

using namespace std;

constexpr int MX = 200001, LG = 19;
int st[MX][LG], m;

void mks() {
  for (int b = 1; b < LG; b++)
    for (int i = 1; i <= m; i++) st[i][b] = st[st[i][b - 1]][b - 1];

}

int query(int n, int x) {
  for (int b = LG - 1; b >= 0; b--)
    if ((n & (1 << b)) != 0) x = st[x][b];
  return x;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> st[i][0];
  mks();
  int q, n, x;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n >> x;
    cout << query(n, x) << '\n';
  }
}