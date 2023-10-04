#include <algorithm>
#include <cstdio>

bool b[9];
int n, v[9], c[9], r, s;
void sol(int d) {
  if (d == n) {
    s = 0;
    for (int i = 0; i < n - 1; i++) s += std::abs(v[c[i]] - v[c[i + 1]]);
    r = std::max(r, s);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (b[i]) continue;
    b[i] = 1, c[d] = i;
    sol(d + 1);
    b[i] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sol(0);
  printf("%d", r);
}