#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> vv;

int clc(int pos, int axs = 0) {
  // 1: x, 0: y
  int res = 0, cnt = 1;
  char cur = axs ? vv[pos][0] : vv[0][pos];
  if (axs) {
    for (int i = 1; i < n; i++) {
      if (cur == vv[pos][i])
        ++cnt;
      else {
        res = max(res, cnt);
        cnt = 1;
        cur = vv[pos][i];
      }
    }
    res = max(res, cnt);
  } else {
    for (int i = 1; i < n; i++) {
      if (cur == vv[i][pos])
        ++cnt;
      else {
        res = max(res, cnt);
        cnt = 1;
        cur = vv[i][pos];
      }
    }
    res = max(res, cnt);
  }
  return res;
}

int init() {
  string s;
  for (auto& v : vv) {
    cin >> s;
    for (int i = 0; i < n; i++) v[i] = s[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, clc(i));
    res = max(res, clc(i, 1));
  }
  return res;
}

int sol() {
  vv.assign(n, vector<char>(n));
  int res = init();

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (x + 1 < n && vv[y][x] != vv[y][x + 1]) {
        swap(vv[y][x], vv[y][x + 1]);
        res = max(res, clc(x));
        res = max(res, clc(x + 1));
        res = max(res, clc(x, 1));
        swap(vv[y][x], vv[y][x + 1]);
      }
      if (y + 1 < n && vv[y][x] != vv[y + 1][x]) {
        swap(vv[y][x], vv[y + 1][x]);
        res = max(res, clc(y, 1));
        res = max(res, clc(y + 1, 1));
        res = max(res, clc(y));
        swap(vv[y][x], vv[y + 1][x]);
      }
    }
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}