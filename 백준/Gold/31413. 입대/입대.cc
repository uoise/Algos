#include <algorithm>
#include <cstdio>

constexpr int MX = 1001;
int n, m, a, d, s[MX * 2], v[MX * 2][MX], r = MX * MX + 1;
int sol() {
  for (int i = 1; i <= n; i++) v[i][0] = v[i - 1][0] + s[i];
  if (v[n][0] >= m) return 0;
  for (int i = d; i < n + d; i++) {
    for (int j = 1; j <= n; j++) {
      v[i][j] = std::max({v[i][j], v[i - 1][j] + s[i], v[i - d][j - 1] + a});
      if (v[i][j] >= m) r = std::min(r, j);
    }
  }
  return r > MX * MX ? -1 : r;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  scanf("%d %d", &a, &d);
  printf("%d", sol());
}