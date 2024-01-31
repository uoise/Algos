#include <cstdio>

int n, m, r;
char s[50][51], t[50][51];
void clc(int y, int x) {
  for (int i = 0; i < 9; i++)
    s[y + i / 3][x + i % 3] = s[y + i / 3][x + i % 3] == '0' ? '1' : '0';
}

int sol() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) scanf("%s", s[y]);
  for (int y = 0; y < n; y++) scanf("%s", t[y]);
  for (int y = 0; y < n - 2; y++) {
    for (int x = 0; x < m - 2; x++) {
      if (s[y][x] == t[y][x]) continue;
      clc(y, x);
      ++r;
    }
  }

  for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
      if (s[y][x] != t[y][x]) return -1;

  return r;
}

int main() { printf("%d", sol()); }