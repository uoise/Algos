#include <cstdio>
#include <queue>

struct zyx {
  int z, y, x;
};

constexpr int xx[] = {1, 0, 0, -1, 0, 0}, yy[] = {0, 1, 0, 0, -1, 0},
              zz[] = {0, 0, 1, 0, 0, -1};
std::queue<zyx> q;
int vvv[30][30][30];
int TC, l, r, c, z, y, x, nz, ny, nx, v, res;
void pre() {
  q = std::queue<zyx>();
  for (z = 0; z < l; z++)
    for (y = 0; y < r; y++)
      for (x = 0; x < c; x++)
        if (vvv[z][y][x] == -2) {
          q.push({z, y, x});
          vvv[z][y][x] = 1;
          return;
        }
}

int sol() {
  while (!q.empty()) {
    z = q.front().z, y = q.front().y, x = q.front().x;
    v = vvv[z][y][x];
    q.pop();
    for (int d = 0; d < 6; d++) {
      nz = z + zz[d], ny = y + yy[d], nx = x + xx[d];
      if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c) continue;
      if (vvv[nz][ny][nx] == -2) return v;
      if (vvv[nz][ny][nx]) continue;
      vvv[nz][ny][nx] = v + 1;
      q.push({nz, ny, nx});
    }
  }
  return 0;
}

int main() {
  char inp[31];
  while (1) {
    scanf("%d %d %d", &l, &r, &c);
    if (!l && !r && !c) break;
    for (z = 0; z < l; z++) {
      for (y = 0; y < r; y++) {
        scanf("%s", inp);
        for (x = 0; x < c; x++)
          vvv[z][y][x] = inp[x] == '.' ? 0 : inp[x] == '#' ? -1 : -2;
      }
    }
    pre();
    if (res = sol())
      printf("Escaped in %d minute(s).\n", res);
    else
      printf("Trapped!\n");
  }
}