#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int MX = 1e5 + 1;

int n, r;
char v[3][MX];
void tgg(int y, int x) { v[y][x] = v[y][x] == '0' ? '1' : '0'; }
int sol(int x) {
  int r = x;
  for (int i = 0; i < n - 1; i++) {
    if (v[x][i] == v[2][i]) continue;
    ++r;
    for (int j = 0; (j < 3) && (i + j < n); j++) tgg(x, i + j);
  }

  return memcmp(v[x], v[2], sizeof v[2]) ? MX * 2 : r;
}

int main() {
  scanf("%d %s %s", &n, v[0], v[2]);
  memcpy(v[1], v[0], sizeof v[0]);
  tgg(1, 0);
  tgg(1, 1);
  r = std::min(sol(0), sol(1));
  printf("%d", r > MX ? -1 : r);
}