#include <iostream>

using namespace std;

constexpr int MX = 2001;
int sv[MX][MX], rv[MX][MX], n, m, k;
int sol() {
  int res = k * k;
  string rs;
  for (int y = 1; y <= n; y++) {
    cin >> rs;
    for (int x = 1; x <= m; x++) {
      sv[y][x] = sv[y][x - 1];
      if (x > k && sv[y][x] &&
          ((rs[x - k - 1] == 'B') ^ ((y + x - k) % 2 == 0)))
        sv[y][x]--;
      if (sv[y][x] < k && ((rs[x - 1] == 'B') ^ ((y + x) % 2 == 0))) sv[y][x]++;
    }
  }

  if (n <= 1 || m <= 1 || k <= 1) return 0;

  for (int x = k; x <= m; x++) {
    for (int y = 1; y <= k; y++) rv[k][x] += sv[y][x];
    res = min(res, min(rv[k][x], k * k - rv[k][x]));
    for (int y = k + 1; y <= n; y++) {
      rv[y][x] = rv[y - 1][x] - sv[y - k][x] + sv[y][x];
      res = min(res, min(rv[y][x], k * k - rv[y][x]));
    }
  }

  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> k;
  cout << sol();
}