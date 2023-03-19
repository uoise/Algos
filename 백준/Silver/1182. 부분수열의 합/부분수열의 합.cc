#include <algorithm>
#include <cstdio>

int n, v[20], s, r, x;
void sol(int p, int l) {
  if (x == s && (p || l)) ++r;
  if (l == n) return;
  for (int i = p; i < n; i++) {
    x += v[i];
    sol(i + 1, l + 1);
    x -= v[i];
  }
}

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  sol(0, 0);
  printf("%d", r);
}