#include <algorithm>
#include <cstdio>

int n, m, l, r, s = 2e9 + 2, v[100001];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);

  while (l < n && r < n) {
    if (v[r] - v[l] >= m) s = std::min(s, v[r] - v[l++]);
    else ++r;
  }

  printf("%d", s);
}