#include <cmath>
#include <cstdio>

double a[250001];
int n, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = log2(x);
  }

  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) continue;
    int t = ceil(a[i - 1] - a[i]);
    r += t, a[i] += t;
  }

  printf("%d", r);
}