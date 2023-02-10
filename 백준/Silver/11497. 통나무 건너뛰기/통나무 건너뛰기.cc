#include <algorithm>
#include <cstdio>

using namespace std;

int T, n, v[10000], r;
int main() {
  scanf("%d", &T);
  while (T--) {
    r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v, v + n);
    for (int i = 2; i < n; i++) r = max(r, (v[i] - v[i - 2]));
    printf("%d\n", r);
  }
}