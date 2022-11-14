#include <iostream>

using namespace std;

int h, w, x, y, rv[301][301], vv[1001][1001];
void inp() {
  cin >> h >> w >> x >> y;
  for (int i = 0; i < h + x; i++)
    for (int j = 0; j < w + y; j++) cin >> vv[i][j];
}

void sol() {
  for (int i = 0; i < h + x; i++)
    for (int j = 0; j < w + y; j++) {
      if (!(i >= x && j >= y) && (i < h && j < w))
        rv[i][j] = vv[i][j];
      else if ((i >= h || j >= w) && vv[i][j])
        rv[i - x][j - y] = vv[i][j];
    }
  for (int i = x; i < h; i++)
    for (int j = y; j < w; j++) rv[i][j] = vv[i][j] - rv[i - x][j - y];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) cout << rv[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  inp();
  sol();
}
