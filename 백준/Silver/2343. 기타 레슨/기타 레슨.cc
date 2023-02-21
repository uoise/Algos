#include <cstdio>

int n, m, v[100000], c, s;
bool clc(const int& mxx) {
  c = 1, s = 0;
  for (int i = 0; i < n; i++) {
    if (mxx < v[i]) return 0;
    if (s + v[i] <= mxx)
      s += v[i];
    else
      c++, s = v[i];
  }
  return m >= c;
}

int sol() {
  int b = 1, e = 1e9, mid, res;
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
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  printf("%d", sol());
}