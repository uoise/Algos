#include <algorithm>
#include <cstdio>

using iip = std::pair<int, int>;

iip vv[100000];
bool cmp(const iip& x, const iip& y) { return (x.first - y.first) < 0; }
int sol() {
  int n, m, r = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &vv[i].first, &vv[i].second);
  std::sort(vv, vv + n, cmp);
  m = vv[0].second;
  for (int i = 1; i < n; i++)
    if (m > vv[i].second) {
      m = vv[i].second;
      ++r;
    }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}