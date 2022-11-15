#include <cstdio>
int main() {
  int n, r = 31, m = 1234567891;
  long long h = 0, x = 1;
  char c;
  scanf("%d ", &n);
  while (n--) {
    scanf("%c", &c);
    h = (h + (x * (c - 'a' + 1) % m)) % m;
    x = x * r % m;
  }
  printf("%d", h);
}