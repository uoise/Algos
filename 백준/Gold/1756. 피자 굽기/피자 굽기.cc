#include <cstdio>

constexpr int MX = 3e5 + 1;
int d, n, o[MX], p[MX];
int sol() {
  for (int i = d; i; i--) {
    if (o[i] < p[n]) continue;
    if (!--n) return i;
  }

  return 0;
}

int main() {
  scanf("%d %d", &d, &n);
  for (int i = 1; i <= d; i++) {
    scanf("%d", &o[i]);
    if (i != 1) o[i] = o[i] > o[i - 1] ? o[i - 1] : o[i];
  }
  for (int i = n; i; i--) scanf("%d", &p[i]);

  printf("%d", sol());
}