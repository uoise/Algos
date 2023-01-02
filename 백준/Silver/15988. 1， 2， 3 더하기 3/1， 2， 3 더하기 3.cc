#include <cstdio>
constexpr int qt = 1e9 + 9, sz = 1e6 + 1;
int TC, x, dp[sz] = {0, 1, 2, 4};
int main() {
  for (int i = 4; i < sz; i++)
    dp[i] = ((dp[i - 1] + dp[i - 2]) % qt + dp[i - 3]) % qt;
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d", &x);
    printf("%d\n", dp[x]);
  }
}