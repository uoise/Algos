#include <algorithm>
#include <cstdio>

constexpr int cv[] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
long long dp[101];
void sol() {
  for (int i = 2; i < 9; i++) dp[i] = cv[i];
  dp[6] = 6;
  for (int i = 9; i < 101; i++) {
    dp[i] = dp[i - 2] * 10 + cv[2];
    for (int j = 3; j < 8; j++) dp[i] = std::min(dp[i], dp[i - j] * 10 + cv[j]);
  }
}

int main() {
  int T, n;
  sol();
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%lld %d", dp[n], n % 2 ? 7 : 1);
    for (int i = 0; i < n / 2 - 1; i++) printf("1");
    printf("\n");
  }
}