#include <cstdio>

int l, w, h, n, v[20];
long long res;
bool b;
void sol(const int l, const int w, const int h) {
  if (!l || !w || !h) return;
  b = 0;
  int x = 1 << 20;
  for (int i = 19; i >= 0; i--) {
    x >>= 1;
    if (!v[i] || l < x || w < x || h < x) continue;
    ++res, --v[i], b = 1;
    break;
  }
  if (!b) return;
  sol(x, w - x, x);
  sol(l - x, w, x);
  sol(l, w, h - x);
}

int main() {
  scanf("%d %d %d %d", &l, &w, &h, &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    scanf("%d", &v[x]);
  }
  sol(l, w, h);
  printf("%lld", b ? res : -1);
}