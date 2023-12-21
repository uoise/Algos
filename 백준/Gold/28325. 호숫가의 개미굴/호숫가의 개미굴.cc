#include <algorithm>
#include <cstdio>

using ll = long long;
constexpr ll MX = 25e4 + 1;
int n;
ll v[MX][2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &v[i][0]);
  for (int i = 1; i <= n; i++) {
    v[i][0] += std::max(v[(i - 1) % n][0], v[(i - 1) % n][1]);
    v[i][1] += v[(i - 1) % n][0] + 1;
  }
  printf("%lld", std::max(v[n][0], v[n][1]));
}