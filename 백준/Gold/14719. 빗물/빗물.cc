#include <algorithm>
#include <cstdio>

using namespace std;

int w, h, l, r, res, vv[502];
int main() {
  scanf("%d %d", &h, &w);
  for (int i = 0; i < w; i++) scanf("%d", &vv[i]);
  for (int i = 1; i < w - 1; i++) {
    l = r = 0;
    for (int j = 0; j <= i; j++) l = max(l, vv[j]);
    for (int j = i; j < w; j++) r = max(r, vv[j]);
    if (vv[i] < min(l, r)) res += min(l, r) - vv[i];
  }
  printf("%d", res);
}