#include <cstdio>
long long n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &n);
    printf("%d\n", n % 10 ? 0 : 1);
  }
}