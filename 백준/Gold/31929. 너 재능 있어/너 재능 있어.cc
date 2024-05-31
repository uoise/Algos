#include <algorithm>
#include <cstdio>

int n, w[1001], m, l[1001], k, r[1001][1001];
int clc(int p, int l) {
  int t = p % k;
  t = (t + k) % k;
  return p - (t ? std::min(t, l) : l);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d ", &w[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d ", &l[i]);
  scanf("%d", &k);

  for (int i = 1; i <= n; i++) r[i][0] = r[i - 1][0] + w[i];
  for (int i = 1; i <= m; i++) r[0][i] = clc(r[0][i - 1], l[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      r[i][j] = std::max(r[i - 1][j] + w[i], clc(r[i][j - 1], l[j]));

  printf("%d", r[n][m]);
}