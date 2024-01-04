#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 4001;
char s[MX], e[MX];
int x, y, r, v[MX][MX];
int main() {
  scanf("%s %s", s, e);
  x = strlen(s), y = strlen(e);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (s[i] != e[j]) continue;
      v[i][j] = 1;
      if (i && j) v[i][j] += v[i - 1][j - 1];
      r = std::max(r, v[i][j]);
    }
  }
  printf("%d", r);
}