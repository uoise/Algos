#include <cstdio>
int dp[1001];
int sol(int n) {
  if (n <= 3) return dp[n] = n;
  if (dp[n]) return dp[n];
  return dp[n] = (sol(n - 1) + sol(n - 2)) % 10007;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", sol(n));
}