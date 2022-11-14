#include <iostream>
using ll = long long;
int nv[8], r = 40320;
bool dp[8][8][8], bv[8];

bool ccw(const ll beg, const ll mid, const ll end) {
  return beg * beg * end * end * 2 <= mid * mid * (beg + end) * (beg + end);
}
void mkr(int cnt) {
  if (cnt == 8) {
    for (int i = 0; i < 8; i++)
      if (!dp[nv[i]][nv[(i + 1) % 8]][nv[(i + 2) % 8]]) {
        --r;
        break;
      }
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (!bv[i]) {
      bv[i] = 1, nv[cnt] = i;
      mkr(cnt + 1);
      bv[i] = 0, nv[cnt] = 0;
    }
  }
}

void sol() {
  for (auto& i : nv) scanf("%d", &i);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      for (int k = 0; k < 8; k++)
        if (i != j && j != k && k != i) dp[i][j][k] = ccw(nv[i], nv[j], nv[k]);
  for (auto& i : nv) i = 0;
  mkr(0);
  printf("%d", r);
}

int main() { sol(); }