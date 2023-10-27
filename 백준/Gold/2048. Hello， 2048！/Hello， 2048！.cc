#include <cstdio>

int sol(int l, int r) {
  if (l == r) return l;
  if (!l && r == 3) return 5;
  if (r == l + 1 && r <= 3) return r + 1;
  return r;
}

int main() {
  int T, l, r;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &l, &r);
    printf("%d\n", sol(l, r));
  }
}