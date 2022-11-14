#include <algorithm>
#include <iostream>
#define ll long long

int n, m, v[1000001];
ll chk(const int& hgt) {
  ll res = 0;
  for (int i = 1; i <= n; i++)
    if (v[i] >= hgt) res += (v[i] - hgt);
  return res;
}
int solve(const int& siz) {
  ll res, mid, beg = 0, end = v[n] + 1;
  while (beg + end > 0) {
    mid = (beg + end) / 2;
    res = chk(mid);
    if (res >= siz && chk(mid + 1) < siz) return mid;
    if (res > siz)
      beg = mid;
    else
      end = mid;
  }
  return mid;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  std::sort(v + 1, v + 1 + n);
  printf("%d\n", solve(m));
}