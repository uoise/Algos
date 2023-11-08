#include <cstdio>

int n, v[100001];
long long pv[100001];
int main() {
  int q, s, e;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    pv[i] = v[i] * v[i] + pv[i - 1];
    v[i] += v[i - 1];
  }

  while (q--) {
    scanf("%d %d", &s, &e);
    long long a = pv[e] - pv[s - 1], b = v[e] - v[s - 1];
    printf("%lld\n", (b * b - a) / 2);
  }
}