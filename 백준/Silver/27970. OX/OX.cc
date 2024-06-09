#include <cstdio>
constexpr long long d = 1e9 + 7LL;
long long r = 0, x = 1;
char s[100001];
int main() {
  scanf("%s", s);
  for (int i = 0; s[i] != '\0'; i++) {
    r = (r + x * (s[i] == 'O')) % d;
    x = (x * 2) % d;
  }
  printf("%lld", r);
}