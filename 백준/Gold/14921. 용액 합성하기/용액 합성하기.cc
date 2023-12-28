#include <algorithm>
#include <cstdio>

int n, v[100001], s, e, t, r = 2e9 + 1;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  e = n - 1;
  while (s < e) {
    t = v[s] + v[e];
    if (std::abs(t) < std::abs(r)) r = t;
    if (!r) break;
    if (t > 0) --e; 
    else ++s;
  }
  printf("%d", r);
}