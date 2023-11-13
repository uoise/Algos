#include <algorithm>
#include <cstdio>

int n, d, k, c, s, r, vv[3000001], iv[3001];
int main() {
  scanf("%d %d %d %d", &n, &d, &k, &c);
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  for (int i = 0; i < n + k; i++) {
    if (!iv[vv[i % n]]++) ++s;
    if (i < k) continue;
    if (!--iv[vv[(i - k) % n]]) --s;
    r = std::max(r, iv[c] ? s : s + 1);
  }
  printf("%d", r);
}