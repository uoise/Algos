#include <algorithm>
#include <cstdio>

int n, v[100001], l, r, m = 2e9 + 1, s, a, ll, rr;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  r = n - 1;
  while (l < r) {
    s = v[l] + v[r];
    a = s > 0 ? s : s * -1;
    if (m > a) m = a, ll = l, rr = r;
    if (!m) break;
    if (s < 0)
      l++;
    else
      r--;
  }
  printf("%d %d", v[ll], v[rr]);
}