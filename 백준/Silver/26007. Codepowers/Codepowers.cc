#include <cstdio>

int n, v[100001];
int main() {
  int m, k, x, a, s, e;
  scanf("%d %d %d %d", &n, &m, &k, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    x += a;
    v[i] = x < k ? 1 : 0;
    if (i > 1) v[i] += v[i - 1];
  }
  while (m--) {
    scanf("%d %d", &s, &e);
    printf("%d\n", v[e - 1] - v[s - 1]);
  }
}