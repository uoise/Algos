#include <algorithm>
#include <cstdio>
#include <unordered_map>

std::unordered_map<int, int> kv;
int main() {
  int q, o, x;
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &o, &x);
    if (o == 1) {
      int m = -1;
      for (int i = 0; i < 4; i++) m = std::max(m, kv[x + i]);
      for (int i = 0; i < 4; i++) kv[x + i] = m + 1;
    } else if (o == 2) {
      kv[x] += 4;
    } else {
      printf("%d\n", kv[x]);
    }
  }
}