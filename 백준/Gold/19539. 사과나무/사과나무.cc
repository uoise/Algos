#include <cstdio>

int n, v, t, s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    t += v / 2, s += v;
  }
  printf("%s", !(s % 3) && (t >= s / 3) ? "YES" : "NO");
}