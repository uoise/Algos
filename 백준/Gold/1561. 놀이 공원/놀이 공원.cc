#include <cstdio>

int n, m, v[10001], t[10001], res, lst;
long long beg, end, mid, inf, s;
bool clc(const long long& tim) {
  s = m, lst = 0;
  for (int i = 0; i < m && s <= inf; i++) {
    s += tim / v[i];
    if (!(tim % v[i])) t[lst++] = i;
  }
  return s >= n;
}

int sol() {
  if (n <= m) return n;
  beg = m, inf = 2LL * n, end = 30LL * n;
  while (beg <= end) {
    mid = (beg + end) / 2;
    if (clc(mid)) {
      if (lst >= s % n) res = t[lst - (s % n) - 1];
      end = mid - 1;
    } else
      beg = mid + 1;
  }
  return res + 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", &v[i]);
  printf("%d", sol());
}