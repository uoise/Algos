#include <iostream>
#define ll long long
int n, k;
ll solve(int beg, int end) {
  if (beg > end) return beg;
  ll val = 0;
  int mid = (beg + end) / 2;
  for (int i = 1; i <= n; i++) {
    val += mid / i < n ? mid / i : n;  // !!!
  }

  if (val < k)
    return solve(mid + 1, end);
  else
    return solve(beg, mid - 1);
}

int main() {
  scanf("%d %d", &n, &k);
  printf("%d\n", solve(1, k));
}