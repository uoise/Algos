#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[3], l, r;
long long s, x = 3e9 + 1, v[5000];
void sol() {
  for (int i = 0; i < n - 2; i++) {
    l = i + 1, r = n - 1;
    while (l < r) {
      s = v[i] + v[l] + v[r];
      if (x > abs(s)) {
        x = abs(s);
        a[0] = v[i], a[1] = v[l], a[2] = v[r];
        if (!x) return;
      }
      if (s > 0) --r;
      else ++l;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
  sort(v, v + n);
  sol();
  for (int i = 0; i < 3; i++) printf("%d ", a[i]);
}