#include <algorithm>
#include <iostream>

int n, c, v[200001];
int chk(const int& lgt) {
  int res = 1, lst = 0;
  for (int i = 1; i < n; i++)
    if (v[i] - v[lst] >= lgt) {
      res++;
      lst = i;
    }
  return res;
}
int solve() {
  int res, val, beg = 0, end = v[n - 1];
  while (beg + 1 < end) {
    res = (beg + end) / 2;
    val = chk(res);
    if (val >= c && chk(res + 1) < c) break;
    if (val < c)
      end = res;
    else
      beg = res;
  }
  return res;
}
int main() {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  printf("%d\n", solve());
}