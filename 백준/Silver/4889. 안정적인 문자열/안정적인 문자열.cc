#include <cstdio>
char s[2001];
int o, c, t;
int main() {
  while (1) {
    scanf("%s", s);
    if (s[0] == '-') break;
    c = 0, t = 0;
    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == '{') ++c;
      else if (--c == -1) ++t, c = 1;
    }
    printf("%d. %d\n", ++o, t + c / 2);
  }
}