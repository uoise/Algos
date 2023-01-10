#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int INF = 1e9 + 1;
int n, cv[1000][3], dp[1000][3], res = INF;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d %d", &cv[i][0], &cv[i][1], &cv[i][2]);
  for (int s = 0; s < 3; s++) {
    dp[0][s] = cv[0][s];
    dp[0][(s + 1) % 3] = dp[0][(s + 2) % 3] = INF;
    for (int i = 1; i < n; i++) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cv[i][0];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cv[i][1];
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cv[i][2];
    }
    res = min(res, min(dp[n - 1][(s + 1) % 3], dp[n - 1][(s + 2) % 3]));
  }
  printf("%d", res);
}