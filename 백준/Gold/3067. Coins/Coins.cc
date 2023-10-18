#include <cstdio>
#include <cstring>

int n, v[21], dp[10001], m;
int sol() {
  memset(dp, 0, sizeof dp);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  scanf("%d", &m);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = v[i]; j <= m; j++) dp[j] += dp[j - v[i]];
  return dp[m];
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}