#include <algorithm>
#include <cstdio>

using namespace std;
bool l;
int t, w, r, v[1001], dp[31][2][1001];
int main() {
  scanf("%d %d", &t, &w);
  for (int i = 1; i <= t; i++) scanf("%d", &v[i]);
  for (int j = 0; j <= w; j++) {
    for (int i = 1; i <= t; i++) {
      l = (v[i] == 1);
      if (j == 0) {
        dp[j][0][i] = dp[j][0][i - 1] + l;
      } else {
        dp[j][0][i] = max(dp[j][0][i - 1], dp[j - 1][1][i - 1]) + l;
        dp[j][1][i] = max(dp[j][1][i - 1], dp[j - 1][0][i - 1]) + !l;
        r = max(r, max(dp[j][0][i], dp[j][1][i]));
      }
    }
  }
  printf("%d", r);
}