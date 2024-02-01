#include <algorithm>
#include <cstdio>

int c, n, v[21][2], dp[100001];
int sol() {
  scanf("%d %d", &c, &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &v[i][0], &v[i][1]);
  for (int i = 0; i < n; i++)
    for (int j = 1; j < 100001; j++)
      if (j - v[i][0] >= 0) dp[j] = std::max(dp[j], dp[j - v[i][0]] + v[i][1]);
  for (int i = 1; i < 100001; i++)
    if (dp[i] >= c) return i;
  return 0;
}

int main() { printf("%d", sol()); }