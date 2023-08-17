#include <cstdio>

constexpr int INF = 1e9 + 7;
long long r;
int fow(const int& n, const int& x) {
  if (!x) return 1;
  if (x == 1) return n;
  long long t = fow(n, x / 2);
  t = t * t % INF;
  t = t * (x % 2 ? n : 1) % INF;
  return t;
}

int main() {
  int m, n, s;
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &n, &s);
    r = (r + 1LL * s * fow(n, INF - 2)) % INF;
  }

  printf("%lld", r);
}