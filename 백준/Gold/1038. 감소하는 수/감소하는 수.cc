#include <algorithm>
#include <cstdio>

constexpr int MX = 1022;
long long rv[MX + 1];
int n;
int main() {
  scanf("%d", &n);
  if (n > MX) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= MX + 1; i++) {
    long long x = 0;
    int t = i;
    for (int j = 9; j >= 0; j--) {
      if (t % 2) x = x * 10 + j;
      t >>= 1;
    }
    rv[i - 1] = x;
  }
  std::sort(rv, rv + MX);
  printf("%lld", rv[n]);
}