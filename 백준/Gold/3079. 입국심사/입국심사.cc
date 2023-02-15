#include <algorithm>
#include <cstdio>

using ll = long long;

int n, v[100001];
ll m, s;
bool clc(const ll& tim) {
  s = 0;
  for (int i = 0; i < n && s <= m; i++) s += (tim / v[i]);
  return s >= m;
}

ll sol() {
  ll beg = 1, end = m * v[n - 1], mid, res = m * v[n - 1];
  while (beg <= end) {
    mid = (beg + end) / 2;
    if (clc(mid)) {
      res = std::min(mid, res);
      end = mid - 1;
    } else {
      beg = mid + 1;
    }
  }
  return res;
}

int main() {
  scanf("%d %lld", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  printf("%lld", sol());
}