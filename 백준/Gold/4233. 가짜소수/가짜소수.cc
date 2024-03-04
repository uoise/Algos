#include <cstdio>

using ll = long long;

bool chk(int x) {
  for (int i = 2; i * i <= x; i++) if (!(x % i)) return 1;
  return 0;
}

ll fpw(ll b, ll e, ll d) {
  ll r = 1;
  while (e) {
    if (e & 1) r = r * b % d;
    b = b * b % d, e >>= 1;
  }
  return r;
}

int main() {
  while (1) {
    int a, p;
    scanf("%d %d", &p, &a);
    if (!a && !p) break;
    printf("%s\n", chk(p) && (fpw(a, p, p) == a) ? "yes" : "no");
  }
}