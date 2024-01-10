#include <algorithm>
#include <cstdio>
using namespace std;
int n, v[201], d[201], r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    d[i] = 1;
    for (int j = 0; j <= i; j++)
      if (v[j] < v[i]) d[i] = max(d[i], d[j] + 1);
    r = max(r, d[i]);
  }
  printf("%d", n - r);
}