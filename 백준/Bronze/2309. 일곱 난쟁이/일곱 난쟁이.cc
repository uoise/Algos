#include <algorithm>
#include <cstdio>
int n, v[9], r = -100;
int main() {
  for (int i = 0; i < 9; i++) {
    scanf("%d", &v[i]);
    r += v[i];
  }
  std::sort(v, v + 9);
  for (int i = 0; i < 9; i++)
    for (int j = i + 1; j < 9; j++)
      if (v[i] + v[j] == r) {
        for (int x = 0; x < 9; x++)
          if (x != i && x != j) printf("%d\n", v[x]);
        return 0;
      }
}