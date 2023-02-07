#include <algorithm>
#include <cstdio>
int T, i, v[10];
int main() {
  scanf("%d", &T);
  while (T--) {
    for (i = 0; i < 10; i++) scanf("%d", &v[i]);
    std::sort(v, v + 10);
    printf("%d\n", v[7]);
  }
}