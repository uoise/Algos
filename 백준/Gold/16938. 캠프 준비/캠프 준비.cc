#include <algorithm>
#include <cstdio>

bool b[15];
int n, l, r, x, t, a[15];
void sol(int p, int c, int s) {
  if (c >= 2) {
    int hh = -1, ll = 1e9 + 1;
    for (int i = 0; i < n; i++)
      if (b[i]) hh = std::max(hh, -a[i]), ll = std::min(ll, -a[i]);
    if (s >= l && s <= r && (hh - ll) >= x) ++t;
  }

  for (int i = p; i < n; i++) {
    if (s - a[i] > r) continue;
    b[i] = 1;
    sol(i + 1, c + 1, s - a[i]);
    b[i] = 0;
  }
}

int main() {
  scanf("%d %d %d %d", &n, &l, &r, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] *= -1;
  }

  std::sort(a, a + n);
  sol(0, 0, 0);
  printf("%d", t);
}