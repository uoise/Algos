#include <cstdio>
int Q, n, x;
long long l = 1, mul = 1;
int main() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &x);
    if (x == 3) {
      printf("%lld\n", l);
      continue;
    }
    scanf("%d", &n);
    if (!x) l += n;
    if (x == 1) mul *= n, l *= n;
    if (x == 2) l += mul * n;
  }
}