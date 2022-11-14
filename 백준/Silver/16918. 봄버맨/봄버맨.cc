#include <cstring>
#include <iostream>
using namespace std;

constexpr int MX = 201;
bool vv[MX][MX], rv[MX][MX], fv[MX][MX];
int r, c, n, xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};

void sol() {
  for (int y = 0; y < r; y++) {
    string s;
    cin >> s;
    for (int x = 0; x < c; x++)
      if (s[x] == '.') vv[y][x] = 1;
  }

  if (--n) {
    for (int y = 0; y < r; y++)
      for (int x = 0; x < c; x++)
        if (!vv[y][x]) {
          rv[y][x] = 1;
          for (int i = 0; i < 4; i++) {
            int nx = xx[i] + x, ny = yy[i] + y;
            if (ny >= 0 && ny < r && nx >= 0 && nx < c) rv[ny][nx] = 1;
          }
        }
    memset(vv, 0, sizeof vv);
    for (int y = 0; y < r; y++)
      for (int x = 0; x < c; x++)
        if (!rv[y][x]) {
          vv[y][x] = 1;
          for (int i = 0; i < 4; i++) {
            int nx = xx[i] + x, ny = yy[i] + y;
            if (ny >= 0 && ny < r && nx >= 0 && nx < c) vv[ny][nx] = 1;
          }
        }
  }
    
  n %= 4;
  const auto& rr = (n % 2 ? fv : n ? rv : vv);
  for (int y = 0; y < r; y++) {
    for (int x = 0; x < c; x++) cout << (rr[y][x] ? '.' : 'O');
    cout << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> r >> c >> n;
  sol();
}
