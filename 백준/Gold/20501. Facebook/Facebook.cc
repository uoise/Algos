#include <bitset>
#include <cstdio>

char c[2001];
std::bitset<2001> s[2001];
int main() {
  int n, q, a, b;
  scanf("%d", &n);
  for (int y = 1; y <= n; y++) {
    scanf("%s", c);
    for (int x = 1; x <= n; x++) s[y][x] = c[x - 1] == '1';
  }

  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &a, &b);
    printf("%d\n", (s[a] & s[b]).count());
  }
}