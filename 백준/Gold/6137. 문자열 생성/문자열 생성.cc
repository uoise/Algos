#include <cstdio>

constexpr int MX = 2001;
int n;
char s[MX], t[MX];
bool sol(int lp, int rp) {
  if (lp >= rp || s[lp] < s[rp]) return true;
  if (s[lp] > s[rp]) return false;
  if (s[lp] == s[rp]) return sol(lp + 1, rp - 1);
  return true;
}

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) scanf("%c\n", &s[i]);
  int p = 0, lp = 0, rp = n - 1;
  while (lp <= rp) t[p++] = sol(lp, rp) ? s[lp++] : s[rp--];
  p = 0;
  for (int i = 0; i < n; i++) {
    printf("%c", t[i]);
    if (++p == 80) printf("\n"), p = 0;
  }
}