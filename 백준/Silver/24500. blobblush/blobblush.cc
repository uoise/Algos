#include <cstdio>
long long n, m = 1;
int main() {
  scanf("%lld", &n);
  while (m < n) m = m * 2 + 1;
  if (m == n) printf("1\n%lld", n);
  else printf("2\n%lld\n%lld", m ^ n, n);
}