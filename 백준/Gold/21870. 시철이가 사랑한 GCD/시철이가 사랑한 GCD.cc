#include <cstdio>

int n, r, g, v[200000];
int gcd(const int& x, const int& y) { return y ? gcd(y, x % y) : x; }
void sol(const int& b, const int& e, int sum) {
  if (e - b < 3) {
    for (int i = b; i < e; i++) sum += v[i];
    r = sum > r ? sum : r;
    return;
  }

  const int m = (b + e) >> 1;
  g = v[b];
  for (int i = b; i < m; i++) g = gcd(g, v[i]);
  sol(m, e, sum + g);

  g = v[m];
  for (int i = m; i < e; i++) g = gcd(g, v[i]);
  sol(b, m, sum + g);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sol(0, n, 0);
  printf("%d", r);
}