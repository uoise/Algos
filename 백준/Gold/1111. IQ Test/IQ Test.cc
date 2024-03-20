#include <cstdio>

int n, v[51], r, c;
void sol() {
  if (n == 1) {
    c = -1;
    return;
  }

  if (n == 2) {
    if (v[0] == v[1]) r = v[0];
    else c = -1;
    return;
  }
  
  c = 1;
  int a = 0, x = v[1] - v[0], y = v[2] - v[1];
  if (x) a = y / x;
  int b = v[1] - a * v[0];
  for (int i = 1; i < n; i++) if (v[i] != v[i - 1] * a + b) return;
  c = 0, r = v[n - 1] * a + b;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sol();
  if (c) printf("%c", c == -1 ? 'A' : 'B');
  else printf("%d", r);
}