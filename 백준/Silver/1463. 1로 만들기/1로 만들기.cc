#include <iostream>
int dp[1000001];
int min(const int& a, const int& b) { return a < b ? a : b; }

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 2; i <= N; i++) {
    dp[i] = dp[i - 1];
    if (!(i % 3)) dp[i] = min(dp[i / 3], dp[i]);
    if (!(i % 2)) dp[i] = min(dp[i / 2], dp[i]);
    ++dp[i];
  }
  printf("%d\n", dp[N]);
}