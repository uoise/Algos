#include <cstdio>

constexpr int D = 1e9 + 3;
int n, k, r[1001][1001];
int sol() {
  if (n / 2 < k) return 0;
  for (int i = 0; i <= n; i++) r[i][1] = i, r[i][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= k; j++) r[i][j] = (r[i - 2][j - 1] + r[i - 1][j]) % D;
  return (r[n - 1][k] + r[n - 3][k - 1]) % D;
}

int main() {
  scanf("%d %d", &n, &k);
  printf("%d", sol());
}