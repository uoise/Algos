#include <cstdio>
int n, k, y, x;
char s[300'001];
long long r, t, v[200'000];
int main() {
  scanf("%d %d\n%s", &n, &k, s);
  for (int i = 1; i <= n; i++) v[i] = v[i - 1] + i;
  for (int i = n - 1; i; i--) v[n + n - i] = v[n + n - i - 1] + i;
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'U') --y;
    else if (s[i] == 'D') ++y;
    else if (s[i] == 'L') --x;
    else ++x;
    t = v[y + x + 1];
    if (y + x >= n) t -= ((y + x) & 1 ? n - 1 - y : n - 1 - x);
    else t -= ((y + x) & 1 ? x : y);
    r += t;
  }
  printf("%lld", r + 1);
}