#include <iostream>
long long dp[101][10];
void solve(int N) {
  long long res = 0;
  for (int i = 1; i <= 9; i++) dp[1][i] = 1;
  for (int ii = 2; ii <= N; ii++) {
    for (int i = 0; i <= 9; i++) {
      dp[ii][i] = 0;
      if (i != 0) dp[ii][i] += (dp[ii - 1][i - 1] % 1000000000);
      if (i != 9) dp[ii][i] += (dp[ii - 1][i + 1] % 1000000000);
    }
  }
  for (int i = 0; i <= 9; i++) res += dp[N][i];
  printf("%lld", res % 1000000000);
}

int main() {
  int N;
  scanf("%d", &N);
  solve(N);
}