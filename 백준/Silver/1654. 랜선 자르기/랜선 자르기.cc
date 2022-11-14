#include <algorithm>
#include <iostream>
#define ll long long
int k, n;
ll v[10001];

ll cnt(const int& siz) {
  ll res = 0;
  for (int i = 1; i <= k; i++) res += (v[i] / siz);
  return res;
}

ll solve(const int& s) {
  ll beg = 0, end = v[k] + 1, res, cur;
  while (beg + 1 < end) {
    res = (beg + end) / 2;
    cur = cnt(res);
    if (cur >= s && cnt(res + 1) < s) return res;
    if (cur < s)
      end = res;
    else
      beg = res;
  }
  return res;
}

int main() {
  scanf("%d %d", &k, &n);
  for (int i = 1; i <= k; i++) scanf("%d", &v[i]);
  std::sort(v + 1, v + k + 1);
  printf("%d\n", solve(n));
}