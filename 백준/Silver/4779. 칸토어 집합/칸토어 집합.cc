#include <cmath>
#include <cstdio>
#include <cstring>

int n;
bool r[531441];
void sol(const int& b, const int& e) {
  if (e - b == 1) return;
  if (e - b == 3)
    r[b + 1] = 0;
  else {
    int s = (e - b) / 3;
    sol(b, b + s);
    memset(r + b + s, 0, sizeof(bool) * (s));
    sol(e - s, e);
  }
}

int main() {
  while (~scanf("%d", &n)) {
    n = pow(3, n);
    memset(r, 1, sizeof(bool) * (n));
    sol(0, n);
    for (int i = 0; i < n; i++) printf("%c", r[i] ? '-' : ' ');
    printf("\n");
  }
}