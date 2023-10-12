#include <cstdio>
#include <cstring>

constexpr int MX = (1 << 26) - 1;
int n, v[25], r;
void sol(int c, int d) {
  if (c == MX) {
    r += (1 << (n - d));
    return;
  }

  if (d == n) return;

  sol(c | v[d], d + 1);
  sol(c, d + 1);
}

int main() {
  char s[101];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < strlen(s); j++) {
      v[i] |= (1 << (s[j] - 'a'));
    }
  }
  
  sol(0, 0);
  printf("%d", r);
}