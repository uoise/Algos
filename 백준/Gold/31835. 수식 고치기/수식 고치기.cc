#include <cstdio>

char cp, cr;
bool l, o, r, c;
int n;
int sol() {
  scanf("%d\n%c ", &n, &cp);
  c = l = cp == 'T';
  for (int i = 1; i < n; i += 2) {
    scanf("%c %c ", &cr, &cp);
    l = c;
    o = cr == '|', r = cp == 'T';
    c = o ? (l | r) : (l & r);
  }
  scanf("%c", &cp);
  if (c == (cp == 'T')) return 0;
  if (n != 1 && l == r && o == r) return 2;
  return 1;
}

int main() { printf("%d", sol()); }