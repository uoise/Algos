#include <cstdio>
#include <cstring>
int t, r, n;
char v[80];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(v, 0, sizeof v);
    r = 0, n = 0;
    scanf("%s", v);
    for (int i = 0; v[i]; i++) {
      if (v[i] == 'O')
        r += ++n;
      else
        n = 0;
    }
    printf("%d\n", r);
  }
}