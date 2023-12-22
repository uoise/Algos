#include <algorithm>
#include <cstdio>
#include <cstring>

int n, pv[11];
bool vv[11][11], bv[11][2];
void dfs(int c, int p) {
  bv[c][p] = 1;
  for (int a = 0; a < n; a++)
    if (vv[c][a] && !bv[a][p]) dfs(a, p);
}

bool vld(int p) {
  for (int i = 0; i < n; i++)
    if (!bv[i][p]) return 0;
  return 1;
}

bool chk(int b, int e) {
  if (b != -1) {
    dfs(b, 0);
    if (!vld(0)) return 0;
  }
  if (e != -1) {
    dfs(e, 1);
    if (!vld(1)) return 0;
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  int r = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) scanf("%d", &pv[i]);
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int a;
      scanf("%d", &a);
      vv[i][a - 1] = 1;
    }
  }

  for (int v = 0; v < (1 << (n + 1)) && r; v++) {
    int b = -1, e = -1, ls = 0, rs = 0;
    for (int i = 0; i < n; i++) {
      bv[i][0] = v & (1 << i);
      bv[i][1] = !bv[i][0];
      if (bv[i][1])
        ls += pv[i], b = i;
      else
        rs += pv[i], e = i;
    }
    if (chk(b, e)) r = std::min(r, std::abs(ls - rs));
  }
  printf("%d", r == 0x3f3f3f3f ? -1 : r);
}