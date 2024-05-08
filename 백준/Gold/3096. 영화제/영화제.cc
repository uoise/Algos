#include <algorithm>
#include <bitset>
#include <cstdio>

std::bitset<1001> v[1001];
int n;
long long t, r;
int main() {
  int m, a, b;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &a, &b);
    v[a][b] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      t = (v[i] & v[j]).count();
      r += std::max(t * (t - 1) / 2, 0LL);
    }
  }

  printf("%lld", r);
}