#include <cstdio>
#include <cstring>
char s[11], e[11];
int sol() {
  scanf("%s %s", s, e);
  int sl = strlen(s), el = strlen(e), r = 0;
  if (sl != el) return r;
  for (int i = 0; i < sl; i++) {
    if (s[i] != e[i]) return r;
    if (s[i] == '8') ++r;
  }
  return r;
}
int main() { printf("%d", sol()); }