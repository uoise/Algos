#include <cstdio>
constexpr int MX = 10007;
int n, dp[1001] = {1, 1, 3};
int sol(int x) {
  if (dp[x]) return dp[x];
  return dp[x] = (sol(x - 1) + sol(x - 2) * 2) % MX;
}
int main() {
  scanf("%d", &n);
  printf("%d", sol(n));
}