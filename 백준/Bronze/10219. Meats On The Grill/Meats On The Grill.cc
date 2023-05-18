#include <cstdio>
int T, h, w;
char g[11][12];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &h, &w);
    for (int y = 0; y < h; y++) scanf("%s", g[y]);
    for (int y = h - 1; y >= 0; y--) {
      for (int x = 0; x < w; x++) printf("%c", g[y][x]);
      printf("\n");
    }
  }
}