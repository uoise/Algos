#include <cstdio>

using namespace std;

char wv[4][9];  // l=6, r=2
int res, seq, bv[4], p[4];
void sol(int pos, int drc) {
  if (pos && (bv[pos - 1] < seq)) {
    bv[pos - 1] = seq;
    if ((wv[pos][(p[pos] + 6) % 8]) != (wv[pos - 1][(p[pos - 1] + 2) % 8]))
      sol(pos - 1, -drc);
  }

  if ((pos < 3) && (bv[pos + 1] < seq)) {
    bv[pos + 1] = seq;
    if ((wv[pos][(p[pos] + 2) % 8]) != (wv[pos + 1][(p[pos + 1] + 6) % 8]))
      sol(pos + 1, -drc);
  }
  p[pos] = (p[pos] - drc + 8) % 8;
}

int main() {
  int k, n, r;
  for (int i = 0; i < 4; i++) scanf("%s", &wv[i]);
  scanf("%d", &k);
  while (k--) {
    scanf("%d %d", &n, &r);
    bv[--n] = ++seq;
    sol(n, r);
  }
  for (int i = 0; i < 4; i++)
    if (wv[i][p[i]] - '0') res += (1 << i);
  printf("%d", res);
}