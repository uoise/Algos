#include <iostream>

using namespace std;

int vv[21][3], n, g;
bool rv[101];
void clc(int w, int t) {
  for (int i = 0; i < n; i++)
    if (vv[i][0] == w) {
      ++vv[i][1];
      return;
    }
  for (int i = 0; i < n; i++)
    if (vv[i][0] == 0) {
      vv[i][0] = w;
      vv[i][1] = 1;
      vv[i][2] = t;
      return;
    }
  int mng = 1e9, mnt = 1e9, idx;
  for (int i = 0; i < n; i++) {
    if (mng > vv[i][1])
      mng = vv[i][1], idx = i, mnt = vv[i][2];
    else if (mng == vv[i][1] && mnt > vv[i][2])
      idx = i, mnt = vv[i][2];
  }
  vv[idx][0] = w, vv[idx][1] = 1, vv[idx][2] = t;
}
void sol() {
  int w, lst = 0;
  for (int i = 0; i < g; i++) {
    cin >> w;
    clc(w, i + 1);
  }
  for (int i = 0; i < n; i++) rv[vv[i][0]] = 1;
  for (int i = 1; i < 101; i++)
    if (rv[i]) cout << i << ' ';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> g;
  sol();
}