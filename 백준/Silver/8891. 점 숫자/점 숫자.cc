#include <iostream>

using namespace std;

using iip = pair<int, int>;
iip clc(int a) {
  int i, l = 1, cnt = 0;
  for (; l <= 20000; l++) {
    for (i = 1; i <= l; i++) {
      if (++cnt == a) return {i, l - i + 1};
    }
  }
}

int sol(int a, int b) {
  iip aa = clc(a), bb = clc(b);
  int rx = aa.first + bb.first, ry = aa.second + bb.second, r = 0;
  for (int l = 1; l < rx + ry - 1; l++)
    for (int i = 0; i < l; i++) ++r;
  for (int i = 0; i < rx; i++) ++r;
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int TC, a, b;
  cin >> TC;
  while (TC--) {
    cin >> a >> b;
    cout << sol(a, b) << '\n';
  }
}
