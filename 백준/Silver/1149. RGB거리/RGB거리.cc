#include <iostream>
int arr[1001][3];
int dp[1001][3];
int min(const int a, const int b) { return (a < b) ? a : b; }
void solve() {
  int N, i, res;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d", &arr[i][0]);
    scanf("%d", &arr[i][1]);
    scanf("%d", &arr[i][2]);
  }

  for (i = 1; i <= N; i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
  }
  res = dp[N][0];
  for (int i = 1; i < 3; i++)
    if (res > dp[N][i]) res = dp[N][i];

  printf("%d\n", res);
}

int main() { solve(); }