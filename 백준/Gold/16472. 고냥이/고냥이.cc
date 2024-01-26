#include <algorithm>
#include <cstdio>
#include <cstring>
char s[100001];
int n, m, v[26], c, l, r;
int main() {
  scanf("%d %s", &n, s);
  m = strlen(s);
  for (int i = 0; i < m; i++) {
    if (!v[s[i] - 'a']++) ++c;
    while (c > n)
      if (!--v[s[l++] - 'a']) --c;
    r = std::max(r, i - l + 1);
  }
  printf("%d", r);
}