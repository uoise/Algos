#include <iostream>
int dp[10001][3], arr[10001];
int max(const int a) {
  int res = dp[a][0];
  for (int i = 1; i < 3; i++)
    if (res < dp[a][i]) res = dp[a][i];
  return res;
}
void solve(int N) {
  for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
  for (int i = 1; i <= N; i++) {
    dp[i][0] += max(i - 1);
    dp[i][1] += dp[i - 1][0] + arr[i];
    dp[i][2] += dp[i - 1][1] + arr[i];
  }

  int res = max(N);
  printf("%d\n", res);
}

int main() {
  int N;
  scanf("%d", &N);
  solve(N);
}