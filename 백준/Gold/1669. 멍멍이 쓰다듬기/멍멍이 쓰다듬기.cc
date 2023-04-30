#include <cmath>
#include <cstdio>

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
  scanf("%d %d", &n, &m);
  printf("%lld\n", sol());
}