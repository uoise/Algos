#include <cstdio>

constexpr int MX = 5e6 + 1;
int pr[MX];
void sol(int k) {
  while (k > 1) {
    printf("%d ", pr[k]);
    k /= pr[k];
  }
  printf("\n");
}

int main() {
  for (int i = 1; i < MX; i++) pr[i] = i;
  for (int i = 2; i * i < MX; i++) {
    if (pr[i] != i) continue;
    for (int j = i * i; j < MX; j += i)
      if (pr[j] == j) pr[j] = i;
  }
  int n, k;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &k);
    sol(k);
  }
}