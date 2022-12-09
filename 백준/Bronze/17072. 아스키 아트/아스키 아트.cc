#include <cstdio>
char s[401][401];
int n, m, r, g, b;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d %d %d", &r, &g, &b);
      r = 2126 * r + 7152 * g + 722 * b;
      if(r < 510'000) s[i][j] = 35;
      else if(r < 1'020'000) s[i][j] = 111;
      else if(r < 1'530'000) s[i][j] = 43;
      else if(r < 2'040'000) s[i][j] = 45;
      else  s[i][j] = 46;
    }
  }
  for(int i = 0; i < n; i++) printf("%s\n", s[i]);
}