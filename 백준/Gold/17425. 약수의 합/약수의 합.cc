#include <cstdio>

constexpr int MX = 1e6 + 1;
int T, n;
long long v[MX];
void sol() {
  for (int i = 1; i < MX; i++)
    for (int j = 1; i * j < MX; j++) v[i * j] += i;
  for (int i = 2; i < MX; i++) v[i] += v[i - 1];
}

int main() {
  sol();
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%lld\n", v[n]);
  }
}