#include <cstdio>

long long h1, h2, a1, a2, c1, c2, t1, t2;
int sol() {
  scanf("%lld %lld %lld %lld %lld %lld", &h1, &h2, &a1, &c1, &a2, &c2);
  t1 = (h2 - 1) / a1, t2 = (h1 - 1) / a2;
  if (a1 >= h2) return 1;
  if (a1 < c2) return (c1 >= a2) ? 0 : 2;
  if (a1 > c2) {
    if (c1 > a2 || t1 <= t2) return 1;
    return (c1 == a2) ? 0 : 2;
  }
  if (t1 <= t2) return 0;
  return (c1 >= a2) ? 0 : 2;
}

int main() {
  int T, r;
  scanf("%d", &T);
  while (T--) {
    r = sol();
    printf("%s\n", r ? (r == 1 ? "NARUTO" : "SASUKE") : "DRAW");
  }
}