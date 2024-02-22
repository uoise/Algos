#include <algorithm>
#include <cstdio>

constexpr int INF = 1e9 + 1;
char r[201];
int dp[101][101], p;
int cmb(int n, int m) {
  if (!n || !m) return 1;
  if (dp[n][m]) return dp[n][m];
  return dp[n][m] = std::min(cmb(n - 1, m) + cmb(n, m - 1), INF);
}

void sol(int n, int m, int k) {
  if (!n || !m) {
    while (n--) r[p++] = 'a';
    while (m--) r[p++] = 'z';
    return;
  }

  int c = cmb(n - 1, m);
  if (k < c) {
    r[p++] = 'a';
    sol(n - 1, m, k);
  } else {
    r[p++] = 'z';
    sol(n, m - 1, k - c);
  }
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (k > cmb(n, m)) {
    printf("-1");
  } else {
    sol(n, m, k - 1);
    printf("%s", r);
  }
}