#include <cmath>
#include <cstdio>

int T;
long long n, m;
double r;
int sol() {
  m -= n;
  if (m < 4) return m;
  r = sqrt(m);
  n = round(r);
  return r > n ? n * 2 : n * 2 - 1;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    printf("%lld\n", sol());
  }
}