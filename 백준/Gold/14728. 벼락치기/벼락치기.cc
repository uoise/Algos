#include <algorithm>
#include <cstdio>

int n, t, k[101], s[101], r[101][10001];
int main() {
  scanf("%d %d", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%d %d", &k[i], &s[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t; j++)
      r[i][j] = j < k[i] ? r[i - 1][j] : std::max(r[i - 1][j], r[i - 1][j - k[i]] + s[i]);
  printf("%d", r[n][t]);
}