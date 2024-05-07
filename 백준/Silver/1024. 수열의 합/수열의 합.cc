#include <algorithm>
#include <cstdio>

int n, l, s = -1, v[101], t;
int main() {
  scanf("%d %d", &n, &l);
  for (int i = 2; i <= 100; i++) v[i] = v[i - 1] + i - 1;
  for (; l <= std::min(n, 100); l++) {
    t = n / l * l + v[l] - n;
    if (t % l) continue;
    s = (n - t) / l;
    break;
  }
  if (n == 1 && l == 2) s = 0;
  if (s < 0) printf("-1");
  else for (int i = 0; i < l; i++) printf("%d ", s + i);
}