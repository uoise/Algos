#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MN = 101;
char s[3][MN];
int l[3], dp[MN][MN][MN];
int main() {
  for (int i = 0; i < 3; i++) {
    scanf("%s", s[i]);
    l[i] = strlen(s[i]);
  }

  for (int i = 1; i <= l[0]; i++)
    for (int j = 1; j <= l[1]; j++)
      for (int k = 1; k <= l[2]; k++)
        dp[i][j][k] = (s[0][i - 1] == s[1][j - 1] && s[1][j - 1] == s[2][k - 1])
                          ? dp[i - 1][j - 1][k - 1] + 1
                          : std::max(std::max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
  printf("%d", dp[l[0]][l[1]][l[2]]);
}