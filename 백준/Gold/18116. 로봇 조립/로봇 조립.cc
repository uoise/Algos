#include <cstdio>

constexpr int MX = 1e6 + 1;
char o;
int n, s, e, gv[MX], cv[MX];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return;
  cv[gv[x]] = cv[gv[y]] = cv[gv[x]] + cv[gv[y]];
  gv[x] = y;
}

int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= MX; i++) gv[i] = i, cv[i] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%c ", &o);
    if (o == 'I') {
      scanf("%d %d\n", &s, &e);
      mks(s, e);
    } else {
      scanf("%d\n", &s);
      printf("%d\n", cv[fnd(s)]);
    }
  }
}