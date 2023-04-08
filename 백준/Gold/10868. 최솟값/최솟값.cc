#include <algorithm>
#include <cstdio>

constexpr int MX = 1e5, INF = 0x3f3f3f3f;
int n, m, x, y;
int vv[MX], tv[MX * 4];
void init(int nod, int lft, int rht) {
  if (lft == rht) {
    tv[nod] = vv[lft];
    return;
  }
  init(nod * 2, lft, (lft + rht) / 2);
  init(nod * 2 + 1, (lft + rht) / 2 + 1, rht);
  tv[nod] = std::min(tv[nod * 2], tv[nod * 2 + 1]);
}

int qry(int nod, int beg, int end, int lft, int rht) {
  if (rht < beg || lft > end) return INF;
  if (lft <= beg && end <= rht) return tv[nod];
  return std::min(qry(nod * 2, beg, (beg + end) / 2, lft, rht),
                  qry(nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht));
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  init(1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", qry(1, 0, n - 1, x - 1, y - 1));
  }
}