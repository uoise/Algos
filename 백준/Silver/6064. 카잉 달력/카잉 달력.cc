#include <cstdio>
int T, n, m, x, y;
int sol() {
  for (int i = x - 1; i < n * m; i += m)
    if (i % n == y - 1) return i + 1;
  return -1;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d", &m, &n, &x, &y);
    printf("%d\n", sol());
  }
}