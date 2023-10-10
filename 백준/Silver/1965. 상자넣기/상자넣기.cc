#include <algorithm>
#include <cstdio>

int n, v[1001], dp[1001], r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (v[i] > v[j]) dp[i] = std::max(dp[i], dp[j] + 1);
    r = std::max(r, dp[i]);
  }

  printf("%d", r);
}