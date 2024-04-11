#include <iostream>
#include <string>

using namespace std;
using ll = long long;

constexpr int MN = 15, ML = 51;
string s[MN + 1];
ll dp[1 << MN][100];
int n, k, ci[ML], cs[MN];
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  cin >> k;

  dp[0][0] = 1, ci[0] = 1 % k;
  for (int i = 1; i < ML; i++) ci[i] = (ci[i - 1] * 10) % k;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < s[i].size(); j++)
      cs[i] = (cs[i] * 10 + s[i][j] - '0') % k;

  for (int c = 0; c < (1 << n); c++) {
    for (int i = 0; i < n; i++) {
      if (c & (1 << i)) continue;
      int a = c | (1 << i);
      for (int j = 0; j < k; j++) {
        int nk = ((j * ci[s[i].size()]) % k + cs[i]) % k;
        dp[a][nk] += dp[c][j];
      }
    }
  }

  ll c = dp[(1 << n) - 1][0], p = 1;
  for (int i = 1; i <= n; i++) p *= i;
  ll g = gcd(c, p);

  cout << c / g << '/' << p / g;
}