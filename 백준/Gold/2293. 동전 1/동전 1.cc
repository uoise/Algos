#include <algorithm>
#include <iostream>
int n, k, v[100], dp[10001];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  dp[0] = 1;
  for (int c = 0; c < n; c++) {
    if (v[c] > k) break;
    for (int i = v[c]; i <= k; i++) {
      dp[i] += dp[i - v[c]];
    }
  }
  printf("%d", dp[k]);
}
