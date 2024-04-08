#include <algorithm>
#include <cstdio>

int n, k, v[1000000], l, r, s, c, t;
int sol() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  l = 0, r = n - 1, t = 3e8, c = -1;
  std::sort(v, v + n);
  while (l < r) {
    s = v[l] + v[r];
    int sk = std::abs(k - s);
    if (sk < t) t = sk, c = 1;
    else if (sk == t) ++c;

    if (s > k) --r;
    else ++l;
  }

  return c;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}