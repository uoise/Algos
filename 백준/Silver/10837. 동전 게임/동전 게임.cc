#include <algorithm>
#include <cstdio>

int k, c, n, m;
bool sol() {
  if (std::abs(n - m) < 2) return 1;
  if (n > m) {
    if (k - n + m + 2 < n) return 0;
  } else {
    if (k - m + n + 1 < m) return 0;
  }
  return 1;
}

int main() {
  scanf("%d %d", &k, &c);
  for (int i = 0; i < c; i++) {
    scanf("%d %d", &n, &m);
    printf("%d\n", sol() ? 1 : 0);
  }
}