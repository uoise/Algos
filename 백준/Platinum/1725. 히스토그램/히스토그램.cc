#include <iostream>
#define ll long long
ll mx(const ll& a, const ll& b) { return a > b ? a : b; }
ll mn(const ll& a, const ll& b) { return a < b ? a : b; }
ll solve(int h[], int beg, int end) {
  if (beg == end) return h[beg];
  int mid = (beg + end) / 2;
  ll tr, sr = mx(solve(h, beg, mid), solve(h, mid + 1, end));
  ll li = mid, ri = mid, hi = h[mid];

  while (li > beg && ri < end) {
    if (h[li - 1] > h[ri + 1])
      hi = mn(h[--li], hi);
    else
      hi = mn(h[++ri], hi);
    tr = hi * (ri - li + 1);
    sr = mx(sr, tr);
  }
  while (li > beg) {
    hi = mn(h[--li], hi);
    tr = hi * (ri - li + 1);
    sr = mx(sr, tr);
  }
  while (ri < end) {
    hi = mn(h[++ri], hi);
    tr = hi * (ri - li + 1);
    sr = mx(sr, tr);
  }
  return sr;
}
int main() {
  int n;
  scanf("%d", &n);
  int h[n + 1];
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  printf("%lld\n", solve(h, 1, n));
}
