#include <cstdio>

constexpr int MX = 1e6;

int vv[1 << 21];
int query(int nod, const int& beg, const int& end, const int& pri) {
  if (beg == end) return beg;
  const int mid = (beg + end) >> 1;
  nod <<= 1;
  if (vv[nod] >= pri) return query(nod, beg, mid, pri);
  return query(nod + 1, mid + 1, end, pri - vv[nod]);
}

void update(int nod, const int& beg, const int& end, const int& idx,
            const int& val) {
  if (idx < beg || idx > end) return;
  vv[nod] += val;
  if (beg == end) return;
  const int mid = (beg + end) >> 1;
  nod <<= 1;
  update(nod, beg, mid, idx, val);
  update(nod + 1, mid + 1, end, idx, val);
}

int main() {
  int n, a, b, c;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &a, &b);
    if (a & 1) {
      c = query(1, 1, MX, b);
      printf("%d\n", c);
      update(1, 1, MX, c, -1);
      continue;
    }
    scanf("%d", &c);
    update(1, 1, MX, b, c);
  }
}