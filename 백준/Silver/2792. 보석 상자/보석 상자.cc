#include <algorithm>
#include <cstdio>

int n, m, v[300000], x, s, idx;
bool clc(const int& mxx) {
  s = 0;
  for (int i = 0; i < m; i++) s += v[i] / mxx + (v[i] % mxx ? 1 : 0);
  return s <= n;
}

int sol() {
  if (n == m) return v[m - 1];
  int mid, res, b = 1, e = v[m - 1] + 1;
  while (b <= e) {
    mid = (b + e) / 2;
    if (clc(mid))
      res = mid, e = mid - 1;
    else
      b = mid + 1;
  }
  return res;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", &v[i]);
  std::sort(v, v + m);
  printf("%d", sol());
}