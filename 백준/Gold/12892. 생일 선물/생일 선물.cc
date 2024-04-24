#include <algorithm>
#include <cstdio>

std::pair<int, int> v[100001];
long long r, c;
int n, d, s, e;
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) scanf("%d %d", &v[i].first, &v[i].second);
  std::sort(v, v + n);
  while (s < n && e < n) {
    if (v[e].first - v[s].first < d) {
      c += v[e++].second;
      r = std::max(r, c);
    } else {
      c -= v[s++].second;
    }
  }
  printf("%lld", r);
}