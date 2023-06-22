#include <cstdio>
char s[1000001], c = '_';
int i = -1, r;
int main() {
  scanf("%s", s);
  while (s[++i] != '\0') if (c != s[i]) ++r, c = s[i];
  printf("%d", r / 2);
}