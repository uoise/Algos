#include <cstdio>

int p;
bool sol() {
  long long x, q;
  scanf("%lld", &x);
  int c0 = 0, c1 = 0, c2 = 0, r;
  while (x) {
    q = x / p, r = x % p;
    if (r > 2) return 0;
    c0 += r == 0, c1 += r == 1, c2 += r == 2;
    x = q;
  }
  return !((c1 != 1 || !c2) && (c1 != 2 || c2));
}

int main() {
  scanf("%d", &p);
  for (int i = 0; i < 4; i++) printf("%d ", sol());
}