#include <algorithm>
#include <cstdio>

int s=1111, t=1111, mx, mn = 51, v[6];
long long n, r;
long long sol() {
  if (n == 1) {
    for (int i = 0; i < 6; i++) r += v[i];
    return r - mx;
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (i == j || i + j == 5) continue;
      s = std::min(s, v[i] + v[j]);
      for (int k = 0; k < 6; k++) {
        if (i == k || j == k || i + k == 5 || j + k == 5) continue;
        t = std::min(t, v[i] + v[j] + v[k]);
      }
    }
  }
  r += (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2)) * mn;
  r += 4 * s * ((n - 1) + (n - 2));
  r += 4 * t;

  return r;
}

int main() {
  scanf("%lld", &n);
  for (int i = 0; i < 6; i++) {
    scanf("%d", &v[i]);
    mx = std::max(v[i], mx);
    mn = std::min(v[i], mn);
  }
  printf("%lld", sol());
}