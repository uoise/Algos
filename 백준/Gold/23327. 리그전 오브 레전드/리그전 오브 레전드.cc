#include <cstdio>
int n, v[100001], q, s, e;
long long pv[100001], a, b;
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    pv[i] = v[i] * v[i] + pv[i - 1];
    v[i] += v[i - 1];
  }
  while (q--) {
    scanf("%d %d", &s, &e);
    a = pv[e] - pv[s - 1], b = v[e] - v[s - 1];
    printf("%lld\n", (b * b - a) / 2);
  }
}