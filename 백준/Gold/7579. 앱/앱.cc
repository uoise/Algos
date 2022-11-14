#include <cstring>
#include <iostream>
using namespace std;
int N, M, siz, m[101], c[101];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> m[i];
  for (int i = 1; i <= N; i++) {
    cin >> c[i];
    siz += c[i];
  }
  int dp[siz];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= N; i++)
    for (int j = siz; j >= c[i]; j--) dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
  for (int i = 0; i <= siz; i++)
    if (dp[i] >= M) {
      cout << i;
      break;
    }
}