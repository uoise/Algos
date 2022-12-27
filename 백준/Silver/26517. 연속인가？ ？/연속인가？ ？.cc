#include <cstdio>
int main() {
  long long k, a, b, c, d;
  scanf("%lld\n%lld %lld %lld %lld", &k, &a, &b, &c, &d);
  a = a * k + b, c = c * k + d;
  if (a == c)
    printf("Yes %lld", a);
  else
    printf("No");
}