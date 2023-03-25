#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m, len, t, r;
bool bv[10];
int clc(int x) {
  if (x < 10) return bv[x] ? 0 : 1;
  t = 0;
  while (x) {
    if (bv[x % 10]) return 0;
    x /= 10, ++t;
  }
  return t;
}

int main() {
  scanf("%d %d", &n, &m);
  r = abs(100 - n);
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    bv[t] = 1;
  }

  for (int i = 0; i < 1000000; i++)
    if (len = clc(i)) r = min(r, len + abs(i - n));

  printf("%d", r);
}