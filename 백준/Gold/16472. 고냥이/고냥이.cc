#include <algorithm>
#include <cstdio>
char s[100001];
int n, v[26], c, l, r;
int main() {
  scanf("%d %s", &n, s);
  for (int i = 0; s[i] != '\0'; i++) {
    if (!v[s[i] - 'a']++) ++c;
    while (c > n) if (!--v[s[l++] - 'a']) --c;
    r = std::max(r, i - l + 1);
  }
  printf("%d", r);
}