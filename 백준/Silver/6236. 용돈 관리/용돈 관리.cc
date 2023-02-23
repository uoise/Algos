#include <cstdio>

int n, m, v[100000], s, c, e;
bool clc(const int& mxx) {
  s = mxx, c = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] > mxx) return 0;
    if (s < v[i]) c++, s = mxx;
    s -= v[i];
  }
  return c <= m;
}

int sol() {
  if (n == m) return v[m - 1];
  int mid, res, b = 1;
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
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    e += v[i];
  }
  printf("%d", sol());
}