#include <cstdio>
#include <cstring>
#include <queue>

struct zyx {
  int z, y, x;
};

constexpr int yy[] = {1, -1, 0, 0, 0, 0}, xx[] = {0, 0, 1, -1, 0, 0},
              zz[] = {0, 0, 0, 0, 1, -1}, INF = 0x3f3f3f3f;

std::queue<zyx> q;
int dvvv[4][5][5][5];
int vv[5][5][5], sv[5], rv[5], r = INF;
bool uv[5];
void bfs() {
  int z, y, x, d, nz, ny, nx;
  vv[0][0][0] = 1;
  q.push({0, 0, 0});
  while (!q.empty()) {
    z = q.front().z, y = q.front().y, x = q.front().x;
    q.pop();
    if (z == 4 && y == 4 && x == 4) {
      r = std::min(r, vv[z][y][x] - 1);
      while (!q.empty()) q.pop();
      return;
    }

    for (d = 0; d < 6; d++) {
      nz = z + zz[d], ny = y + yy[d], nx = x + xx[d];
      if (nz < 0 || nz > 4 || ny < 0 || ny > 4 || nx < 0 || nx > 4) continue;
      if (vv[nz][ny][nx]) continue;
      vv[nz][ny][nx] = vv[z][y][x] + 1;
      q.push({nz, ny, nx});
    }
  }
}

bool mks() {
  if (dvvv[rv[0]][sv[0]][0][0] || dvvv[rv[4]][sv[4]][4][4]) return 0;
  for (int i = 0; i < 5; i++)
    memcpy(vv[i], dvvv[rv[i]][sv[i]], sizeof dvvv[rv[i]][sv[i]]);
  return 1;
}

void rot(const int& d) {
  if (r == 12) return;
  if (d == 5) {
    if (mks()) bfs();
    return;
  }

  for (int i = 0; i < 4; i++) {
    rv[d] = i;
    rot(d + 1);
  }
}

void stk(const int& d) {
  if (r == 12) return;
  if (d == 5) {
    const auto &t = dvvv[0][sv[0]], &b = dvvv[0][sv[4]];
    if (t[0][0] && t[0][4] && t[4][0] && t[4][4]) return;
    if (b[0][0] && b[0][4] && b[4][0] && b[4][4]) return;
    rot(0);
    return;
  }

  for (int i = 0; i < 5; i++) {
    if (uv[i]) continue;
    uv[i] = 1, sv[d] = i;
    stk(d + 1);
    uv[i] = 0;
  }
}

int main() {
  int z, y, x, d;
  for (z = 0; z < 5; z++) {
    for (y = 0; y < 5; y++)
      for (x = 0; x < 5; x++) {
        scanf("%d", &d);
        dvvv[0][z][y][x] = d ? 0 : -1;
      }

    for (d = 0; d < 3; d++)
      for (y = 0; y < 5; y++)
        for (x = 0; x < 5; x++) dvvv[d + 1][z][x][4 - y] = dvvv[d][z][y][x];
  }
  stk(0);
  printf("%d", r == INF ? -1 : r);
}