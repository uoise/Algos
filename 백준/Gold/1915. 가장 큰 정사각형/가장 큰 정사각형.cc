#include <algorithm>
#include <cstdio>

constexpr int MX = 1001;
int n, m, r, v[MX][MX];
int clc(const int& a, const int& b, const int& c) {
  return std::min(std::min(a, b), c) + 1;
}

int main() {
  char s[MX];
  scanf("%d %d", &n, &m);
  for (int y = 1; y <= n; y++) {
    scanf("%s", s);
    for (int x = 0; x < m; x++) v[y][x + 1] = s[x] - '0';
  }

  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      if (v[y][x] != 1) continue;
      v[y][x] = clc(v[y - 1][x - 1], v[y - 1][x], v[y][x - 1]);
      r = std::max(r, v[y][x]);
    }
  }

  printf("%d", r * r);
}