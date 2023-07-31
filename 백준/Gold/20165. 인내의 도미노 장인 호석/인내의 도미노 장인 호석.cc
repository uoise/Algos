#include <algorithm>
#include <cstdio>
#include <unordered_map>

constexpr int MX = 101, xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::unordered_map<char, int> dm;
int n, m, vv[MX][MX];
bool bv[MX][MX];
int psh(int y, int x, const int& d) {
  int cnt = 0, lst = 1;
  while (lst) {
    if (!bv[y][x]) lst = std::max(lst, vv[y][x]), ++cnt, bv[y][x] = 1;
    y += yy[d], x += xx[d], --lst;
    if (!y || y > n || !x || x > m) break;
  }

  return cnt;
}

int main() {
  int x, y, r, s = 0;
  char dc;
  dm.insert({'E', 0});
  dm.insert({'W', 2});
  dm.insert({'S', 1});
  dm.insert({'N', 3});
  scanf("%d %d %d", &n, &m, &r);
  for (y = 1; y <= n; y++)
    for (x = 1; x <= m; x++) scanf("%d", &vv[y][x]);

  while (r--) {
    scanf("%d %d %c", &y, &x, &dc);
    s += psh(y, x, dm[dc]);
    scanf("%d %d", &y, &x);
    bv[y][x] = 0;
  }

  printf("%d\n", s);
  for (y = 1; y <= n; y++) {
    for (x = 1; x <= m; x++) printf("%c ", bv[y][x] ? 'F' : 'S');
    printf("\n");
  }
}