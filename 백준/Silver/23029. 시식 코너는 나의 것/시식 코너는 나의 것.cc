#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int MX = 1e5 + 1;
int n, v[MX], dp[MX][3];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    dp[i][1] = dp[i - 1][0] + v[i];
    dp[i][2] = dp[i - 1][1] + v[i] / 2;
  }
  printf("%d", max(dp[n][0], max(dp[n][1], dp[n][2])));
}