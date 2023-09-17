#include <algorithm>
#include <cstdio>

constexpr int MX = 2001;
int n, v[MX], dp[MX], r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    dp[i] = 1;
  }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (v[i] < v[j]) dp[i] = std::max(dp[i], dp[j] + 1);
  for (int i = 0; i < n; i++) r = std::max(r, dp[i]);
  printf("%d", n - r);
}