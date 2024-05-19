#include <cstdio>
#include <queue>

constexpr int MN = 1001, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
char s[MN][MN];
int n, m, b, r;
void bom(int y, int x) {
  switch (s[y][x]) {
    case '|':
      return;
    case '#':
      s[y][x] = '*';
      return;
    case '*':
      s[y][x] = '.';
      ++b, --r;
      q.push({y, x});
      return;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) {
    scanf("%s", s[y]);
    for (int x = 0; x < m; x++) r += (s[y][x] == '*' || s[y][x] == '#');
  }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (s[y][x] != '@') continue;
      s[y][x] = '.';
      for (int d = 0; d < 4; d++) {
        for (int l = 1; l < 3; l++) {
          if (s[y + yy[d] * l][x + xx[d] * l] == '|') break;
          bom(y + yy[d] * l, x + xx[d] * l);
        }
      }
    }
  }

  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) bom(y + yy[d], x + xx[d]);
  }

  printf("%d %d", b, r);
}