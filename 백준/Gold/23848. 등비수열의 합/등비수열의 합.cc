#include <cmath>
#include <cstdio>

long long s, a, r, n, c;
bool sol() {
  n = 3;
  for (r = 2; r <= 1LL * sqrt(s); r++) {
    for (n = 3;; n++) {
      c = (1LL * pow(r, n) - 1) / (r - 1); 
      if (c > s) break;
      if (s % c) continue;
      a = s / c;
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%lld", &s);
  if (sol()) {
    printf("%lld\n", n);
    while (n--) {
      printf("%lld ", a);
      a *= r;
    }
  } else {
    printf("-1");
  }
}