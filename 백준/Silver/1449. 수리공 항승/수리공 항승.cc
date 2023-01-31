#include <cstdio>
int n, l, x, r;
bool v[1001];
int main() {
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    v[x] = 1;
  }
  x = 0;
  for (int i = 0; i < 1001; i++) {
    if (x) --x;
    if (v[i] && !x) x = l, ++r;
  }
  printf("%d", r);
}