#include <cstdio>
int dp[41][2];
void sol(int x) {
  if (dp[x][0] || dp[x][1]) return;
  sol(x - 1), sol(x - 2);
  dp[x][0] = dp[x - 1][0] + dp[x - 2][0];
  dp[x][1] = dp[x - 1][1] + dp[x - 2][1];
}
int main() {
  int n, x;
  dp[0][0]++, dp[1][1]++;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    sol(x);
    printf("%d %d\n", dp[x][0], dp[x][1]);
  }
}