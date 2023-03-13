#include <cstdio>

constexpr int MX = 1e6 + 1;
bool pr[MX];
int T, n, r;
int sol() {
  r = 0;
  for (int i = 2; i <= n / 2; i++)
    if (!pr[i] && !pr[n - i]) r++;
  return r;
}

int main() {
  scanf("%d", &T);

  for (int i = 2; i < MX; i++)
    if (!pr[i])
      for (int j = 2; i * j < MX; j++) pr[i * j] = 1;

  while (T--) {
    scanf("%d", &n);
    printf("%d\n", sol());
  }
}