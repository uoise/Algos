#include <iostream>
using namespace std;
int dp[17], n;
int main() {
  int t, p;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &t, &p);
    dp[i] = max(dp[i], dp[i - 1]);
    if (i + t <= n + 1) dp[i + t] = max(dp[i + t], (dp[i] + p));
  }
  for (int i = 1; i <= n + 1; i++) dp[i] = max(dp[i], dp[i - 1]);
  printf("%d", dp[n + 1]);
}