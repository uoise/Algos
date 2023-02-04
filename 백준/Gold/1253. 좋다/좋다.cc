#include <algorithm>
#include <cstdio>

using namespace std;

int n, v[2000], b, e, t, r;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sort(v, v + n);
  for (int i = 0; i < n; i++) {
    b = 0, e = n - 1;
    while (b < e) {
      if (b == i) ++b;
      if (e == i) --e;
      if(b >= e) break;
      t = v[b] + v[e];
      if (t == v[i]) {
        ++r;
        break;
      }
      if (t < v[i]) ++b;
      else --e;
    }
  }
  printf("%d", r);
}