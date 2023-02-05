#include <cstdio>

int v[1500][1500], n, p[1500], r, ix, mx;
int main() {
  scanf("%d", &n);
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j < n; j++) scanf("%d", &v[i][j]);
  r = n;
  while (r--) {
    mx = -2e9, ix = -1;
    for (int i = 0; i < n; i++)
      if ((p[i] < n) && (mx < v[p[i]][i])) mx = v[p[i]][i], ix = i;
    ++p[ix];
  }
  printf("%d", mx);
}