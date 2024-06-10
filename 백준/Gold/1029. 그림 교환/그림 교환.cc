#include <algorithm>
#include <cstdio>

char s[15][16];
int n, r[1 << 15][15];
int sol(int c, int p, int b) {
  b |= (1 << c);
  int& ci = r[b][c];
  if (ci) return ci;
  for (int a = 1; a < n; a++) {
    if ((b & (1 << a)) || (s[c][a] < p)) continue;
    ci = std::max(ci, sol(a, s[c][a], b) + 1);
  }
  return ci;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  printf("%d", sol(0, 0, 0) + 1);
}