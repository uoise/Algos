#include <cstdio>

int n, k, r;
int clc(int x) {
  int t = 0;
  while (x) {
    t += (x & 1);
    x >>= 1;
  }
  return t;
}

int sol() {
  scanf("%d %d", &n, &k);
  if (n <= k) return 0;
  while (1) {
    int t = clc(n);
    if (t <= k) break;
    ++r, ++n;
  }
  return r;
}

int main() { printf("%d", sol()); }