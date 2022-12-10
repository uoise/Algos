#include <cstring>
#include <iostream>
bool b[3000];
int n, x, r;
int main() {
  for (; EOF != scanf("%d", &n);) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      if (i) b[abs(r - x)] = 1;
      r = x;
    }
    r = 0;
    for (int i = 1; i < n; i++)
      if (b[i]) r++;
    memset(b, 0, sizeof b);
    printf((r == (n - 1) ? "Jolly\n" : "Not jolly\n"));
  }
}