#include <algorithm>
#include <cstdio>

struct ise {
  int i, s, e;
  bool operator<(const ise& o) const { return s == o.s ? e < o.e : s < o.s; }
};

constexpr int MX = 1e5 + 1;
ise vv[MX];
int gv[MX];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  gv[x] = y;
}

int main() {
  int n, s, e, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &vv[i].s, &vv[i].e, &s);
    gv[i] = vv[i].i = i;
  }

  std::sort(vv + 1, vv + 1 + n);

  s = vv[1].s, e = vv[1].e;
  for (int i = 1; i <= n; i++) {
    if (vv[i].s > e) {
      s = vv[i].s, e = vv[i].e;
      continue;
    }

    mks(vv[i - 1].i, vv[i].i);
    e = std::max(e, vv[i].e);
  }

  while (q--) {
    scanf("%d %d", &s, &e);
    printf("%d\n", fnd(s) == fnd(e));
  }
}