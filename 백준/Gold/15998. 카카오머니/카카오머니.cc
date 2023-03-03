#include <cstdio>

using ll = long long;

int n, fst;
ll m, a, b, lst, res;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
int main() {
  scanf("%d", &n);
  while (n--) {
    lst = b;
    scanf("%lld %lld", &a, &b);
    if (res >= 0 && lst + a < 0) {
      if (!fst) {
        res = b - a - lst, m = b, fst = 1;
      } else {
        res = gcd(res, b - a - lst);
        m = m > b ? m : b;
        if (res <= m) res = -1;
      }
    } else if (lst + a != b)
      res = -1;
  }
  printf("%lld", res ? res : 1);
}