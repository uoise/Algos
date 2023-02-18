#include <cstdio>

int n, m, v[5000], c, mn, mx;
bool clc(const int& dif) {
  mn = 2e9, mx = -2e9, c = 0;
  for (int i = 0; i < n; i++) {
    mn = mn > v[i] ? v[i] : mn;
    mx = mx < v[i] ? v[i] : mx;
    if (mx - mn > dif) ++c, mn = v[i], mx = v[i];
  }
  return m > c;
}

int sol() {
  int b = 0, e = 10000, m, r;
  while (b <= e) {
    m = (b + e) / 2;
    if (clc(m))
      r = m, e = m - 1;
    else
      b = m + 1;
    }
  return r;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  printf("%d", sol());
}