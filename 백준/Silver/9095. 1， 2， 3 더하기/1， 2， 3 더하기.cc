#include <cstdio>
int v[12];
int sol(int x) {
  if (v[x]) return v[x];
  return v[x] = sol(x - 1) + sol(x - 2) + sol(x - 3);
}
int main() {
  int T, n;
  v[1] = 1, v[2] = 2, v[3] = 4;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", sol(n));
  }
}