#include <cstdio>

constexpr int MX = 1e5 + 1;
bool pr[MX], d;
long long n;
long long sol() {
  if (n < 3) return 2;
  d = 0;
  while (!d) {
    d = 1;
    for (long long i = 2; (i * i <= n) && d; i++)
      if (!pr[i] && !(n % i)) d = 0;
    n++;
  }
  return n - 1;
}

int main() {
  int T;

  for (int i = 2; i < MX; i++)
    if (!pr[i])
      for (int j = 2; i * j < MX; j++) pr[i * j] = 1;

  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &n);
    printf("%lld\n", sol());
  }
}