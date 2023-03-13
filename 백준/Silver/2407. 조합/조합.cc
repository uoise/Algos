#include <iostream>
#include <string>

using namespace std;

using ml = __uint128_t;
using ll = long long;
ml mx = 1e15;
ml dp[101][101];
ml clc(int n, int m) {
  if (!m || n == m) return 1;
  if (dp[n][m]) return dp[n][m];
  return dp[n][m] = clc(n - 1, m) + clc(n - 1, m - 1);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  ml x = clc(n, m);
  string r = "";
  if ((ll)(x / mx)) r += to_string((ll)(x / mx));
  r += to_string((ll)(x % mx));
  printf("%s", r.c_str());
}