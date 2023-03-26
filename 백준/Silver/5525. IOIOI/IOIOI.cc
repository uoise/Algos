#include <cstdio>

int n, m, v, l, r;
char s[1000001];

void clc() {
  if (v == 2) --l;
  if (l >= n) r += l - n + 1;
}

int main() {
  scanf("%d %d %s", &n, &m, s);
  for (const char& c : s) {
    if (c == '\0') break;
    if (c == 'I') {
      if (v == 1) {
        clc();
        l = 0;
      }
      v = 1;
    } else if (c == 'O' && v == 1)
      v = 2, ++l;
    else {
      clc();
      v = 0, l = 0;
    }
  }
  if (l) clc();
  printf("%d", r);
}