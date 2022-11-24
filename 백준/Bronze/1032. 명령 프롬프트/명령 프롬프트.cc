#include <cstdio>
int n, i;
char c[51], t[51];
int main() {
  scanf("%d\n%s", &n, c);
  while (--n) {
    scanf("%s", t);
    i = 0;
    while (c[i]) {
      if (c[i] != '?') c[i] = (c[i] != t[i] ? '?' : c[i]);
      i++;
    }
  }
  printf("%s", c);
}