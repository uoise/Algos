#include <iostream>
#define MX 501
int arr[MX][MX], dp[MX][MX];

int mxx(const int a, const int b) { return (a > b) ? a : b; }
void solve() {
  int N;
  int ll, rr;
  scanf("%d", &N);

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++) {
      scanf("%d", &arr[i][j]);
      dp[i][j] = arr[i][j];
    }

  for (int i = N - 1; i > 0; i--)
    for (int j = 1; j <= i; j++)
      dp[i][j] += mxx(dp[i + 1][j], dp[i + 1][j + 1]);

  printf("%d\n", dp[1][1]);
}
int main() { solve(); }