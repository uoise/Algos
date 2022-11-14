#include <iostream>
#define MX 301
int arr[MX], dp[MX][3];

int mxx(const int a, const int b) { return (a > b) ? a : b; }
void solve() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    dp[i][1] = arr[i];
    dp[i][2] = arr[i];
  }

  for (int i = 1; i <= N; i++) {
    dp[i][0] += mxx(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] += dp[i - 1][0];
    dp[i][2] += dp[i - 1][1];
  }
  printf("%d\n", mxx(dp[N][1], dp[N][2]));
}
int main() { solve(); }