#include <algorithm>
#include <cstdio>

constexpr int MN = 501;
int n, v[MN][MN];
int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) scanf("%d", &v[y][x]);

  for (int i = 0; i < n; i++)
    for (int y = 0; y < n; y++)
      for (int x = 0; x < n; x++)
        if (x != y) v[y][x] = std::min(v[y][x], v[y][i] + v[i][x]);

  while (m--) {
    int s, e, c;
    scanf("%d %d %d", &s, &e, &c);
    printf("%s\n", v[s - 1][e - 1] > c ? "Stay here" : "Enjoy other party");
  }
}