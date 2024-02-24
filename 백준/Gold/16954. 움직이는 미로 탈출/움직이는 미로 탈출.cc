#include <algorithm>
#include <cstdio>
#include <queue>

struct tp {
  int t, y, x;
};

constexpr int yy[] = {1, 0, -1, 0, 1, 1, -1, -1, 0},
              xx[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
std::queue<tp> q;
char mv[9][8][9];
bool bv[9][8][8];
bool sol() {
  bv[0][7][0] = 1;
  q.push({0, 7, 0});
  while (!q.empty()) {
    auto [t, y, x] = q.front();
    q.pop();
    int nt = std::min(t + 1, 8);
    for (int d = 0; d < 9; d++) {
      int ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny > 7 || nx < 0 || nx > 7) continue;
      if (mv[t][ny][nx] == '#' || bv[nt][ny][nx]) continue;
      if (mv[nt][ny][nx] == '#') continue;
      if (ny == 0 && nx == 7) return 1;
      bv[nt][ny][nx] = 1;
      q.push({nt, ny, nx});
    }
  }
  return 0;
}

int main() {
  for (int y = 0; y < 8; y++) scanf("%s", mv[0][y]);
  for (int t = 1; t < 9; t++) {
    for (int x = 0; x < 8; x++) {
      for (int y = 7; y; y--) mv[t][y][x] = mv[t - 1][y - 1][x];
      mv[t][0][x] = '.';
    }
  }
  printf("%d", sol());
}