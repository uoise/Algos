#include <stdio.h>
char s[50];
int c[26], i, p = -1;
int main() {
  scanf("%s", s);
  while (s[i]) c[s[i++] - 'A']++;
  i = 0;
  for (int j = 0; j < 26; j++)
    if (c[j] % 2) i++, p = j;
  if (i > 1)
    printf("I\'m Sorry Hansoo");
  else {
    --c[p];
    for (int j = 0; j < 26; j++)
      for (i = 0; i < c[j] / 2; i++) printf("%c", 'A' + j);
    if (p >= 0) printf("%c", 'A' + p);
    for (int j = 25; j >= 0; j--)
      for (i = 0; i < c[j] / 2; i++) printf("%c", 'A' + j);
  }
}