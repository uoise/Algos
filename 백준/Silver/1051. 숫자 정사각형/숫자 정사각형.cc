#include <stdio.h>
int n, m;
char c[51][51];
int sol() {
  int r = (n < m ? n : m);
  while (--r) {
    for (int i = 0; i + r < n; i++)
      for (int j = 0; j + r < m; j++)
        if (c[i][j] == c[i][j + r] && c[i][j] == c[i + r][j] &&
            c[i][j] == c[i + r][j + r])
          return (r + 1) * (r + 1);
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", c[i]);
  printf("%d", sol());
}