#include <algorithm>
#include <cstdio>

int x, n, lp, rp, v[1000001];
bool sol() {
  scanf("%d", &n);
  x *= 10000000;
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  if (n < 2) return 1;
  std::sort(v, v + n);
  lp = 0, rp = n - 1;
  while (lp < rp) {
    if (v[lp] + v[rp] == x) {
      printf("yes %d %d\n", v[lp], v[rp]);
      return 0;
    } else if (v[lp] + v[rp] < x) {
      ++lp;
    } else {
      --rp;
    }
  }
  return 1;
}

int main() {
  while (scanf("%d", &x) == 1)
    if (sol()) printf("danger\n");
}