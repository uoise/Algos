#include <iostream>
const int mx = 2100000000;
int N, v[501][2], dp[501][501];
void solve() {
  for (int s = 1; s < N; s++) {
    for (int i = 0; i < N - s; i++) {
      int j = i + s;
      dp[i][j] = mx;
      for (int k = i; k < j; k++) {
        dp[i][j] = std::min(
            dp[i][j], dp[i][k] + dp[k + 1][j] + v[i][0] * v[k][1] * v[j][1]);
      }
    }
  }
  printf("%d\n", dp[0][N - 1]);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d %d", &v[i][0], &v[i][1]);
  solve();
}