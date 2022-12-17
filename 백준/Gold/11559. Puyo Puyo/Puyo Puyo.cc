#include <cstdio>
#include <cstring>
#include <queue>

using qii = std::queue<std::pair<int, int>>;

char sv[12][7];
bool bv[12][7];
int res, xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
bool bfs(int y, int x) {
  qii q, rq;
  char clr = sv[y][x];
  q.push({y, x});
  while (!q.empty()) {
    int cy = q.front().first, cx = q.front().second;
    q.pop();
    bv[cy][cx] = 1;
    rq.push({cy, cx});
    for (int i = 0; i < 4; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (ny < 0 || ny > 11 || nx < 0 || nx > 5) continue;
      if (!bv[ny][nx] && (sv[ny][nx] == clr)) q.push({ny, nx});
    }
  }

  if (rq.size() > 3) {
    while (!rq.empty()) {
      sv[rq.front().first][rq.front().second] = 'X';
      rq.pop();
    }
    return 1;
  }

  return 0;
}

int dfs() {
  int cnt = 0;
  for (int y = 0; y < 12; y++)
    for (int x = 0; x < 6; x++)
      if (!bv[y][x] && sv[y][x] != '.')
        if (bfs(y, x)) ++cnt;
  return cnt;
}

void grv() {
  for (int x = 0; x < 6; x++) {
    for (int y = 11; y >= 0; y--) {
      if (sv[y][x] == 'X')
        for (int i = y - 1; i >= 0; i--) {
          if (sv[i][x] != 'X') {
            std::swap(sv[y][x], sv[i][x]);
            break;
          }
        }
    }
    for (int y = 0; y < 12 && (sv[y][x] == 'X'); y++) sv[y][x] = '.';
  }
}


int main() {
  for (int y = 0; y < 12; y++) scanf("%s", sv[y]);
  while (dfs()) {
    ++res;
    memset(bv, 0, sizeof bv);
    grv();
  }
  printf("%d", res);
}