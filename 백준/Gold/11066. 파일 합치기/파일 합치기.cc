#include <string.h>

#include <iostream>
const int MX = 210000000;
int T, K, c[501], v[501], dp[501][501];
int clc(int beg, int end) {
  if (beg == end) return c[beg];
  int& res = dp[beg][end];
  if (res != -1) return res;
  res = MX;
  int sum = v[end + 1] - v[beg];
  for (int i = beg; i < end; i++)
    res = std::min(res, clc(beg, i) + clc(i + 1, end) + sum);

  return res;
}

void solve() {
  int res = MX;
  for (int i = 1; i <= K; i++) v[i] = v[i - 1] + c[i - 1];
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < K - 1; i++)
    res = std::min(res, clc(0, i) + clc(i + 1, K - 1));
  printf("%d\n", res);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &K);
    for (int i = 0; i < K; i++) scanf("%d", &c[i]);
    solve();
  }
}