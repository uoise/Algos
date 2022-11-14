#include <algorithm>
#include <iostream>

using namespace std;

char rv[16], cv[16], vv[5] = {'a', 'e', 'i', 'o', 'u'};
int L, C;

void prt(int cur, int len) {
  if (len == L) {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < 6; j++)
        if (j == 5)
          ++c2;
        else if (vv[j] == rv[i]) {
          ++c1;
          break;
        }
    }
    if (c1 && c2 > 1) {
      for (int i = 0; i < L; i++) cout << rv[i];
      cout << '\n';
    }
  } else {
    for (int i = cur; i < C; i++) {
      rv[len] = cv[i];
      prt(i + 1, len + 1);
    }
  }
}

void sol() {
  for (int i = 0; i < C; i++) cin >> cv[i];
  sort(cv, cv + C);
  prt(0, 0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> L >> C;
  sol();
}
