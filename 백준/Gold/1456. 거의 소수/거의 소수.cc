#include <cmath>
#include <cstdio>

constexpr int MX = 1e7 + 1;
bool pr[MX];
long long s, e, c, r;
int main() {
  scanf("%lld %lld", &s, &e);
  for (int i = 2; i < MX; i++) {
    if (pr[i]) continue;
    for (int j = 2 * i; j < MX; j += i) pr[j] = 1;
  }

  for (int i = 2; i < MX; i++) {
    if (pr[i]) continue;
    if (1LL * i * i > e) break;
    c = i;
    while (c <= e / i) {
      r += (c * i) >= s;
      c *= i;
    }
  }

  printf("%lld", r);
}