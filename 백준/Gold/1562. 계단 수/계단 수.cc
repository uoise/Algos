#include <cstdio>

constexpr int MX = 1e9;
int n, r, dp[101][10][1 << 10];
int dfs(const int dep, const int pos, const int sts) {
  int& cur = dp[dep][pos][sts];
  if (cur) return cur;
  if (dep == n) return sts == 1023;
  int tmp = 0;
  if (pos) tmp += dfs(dep + 1, pos - 1, sts | 1 << (pos - 1));
  if (pos != 9) tmp += dfs(dep + 1, pos + 1, sts | 1 << (pos + 1));
  return cur = tmp % MX;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < 10; i++) r = (r + dfs(1, i, 1 << i)) % MX;
  printf("%d", r);
}