#include <algorithm>
#include <cstdio>

int n, m, v[10000], c;
bool clc(const int& mxx) {
  c = 0;
  for (int i = 0; i < n; i++) c += (mxx < v[i] ? mxx : v[i]);
  return m >= c;
}

int sol() {
  int b = 0, e = v[n - 1], mid, res;
  while (b <= e) {
    mid = (b + e) / 2;
    if (clc(mid))
      res = mid, b = mid + 1;
    else
      e = mid - 1;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  scanf("%d", &m);
  printf("%d", sol());
}