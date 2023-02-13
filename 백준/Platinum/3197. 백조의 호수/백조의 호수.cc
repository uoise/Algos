#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct vyx {
  int v, y, x;
  bool operator<(const vyx& a) const { return v > a.v; }
};

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, MX = 1500;
int r, c, t, y, x, ny, nx, vv[MX][MX];
bool bv[MX][MX];
queue<pair<int, int>> q;
priority_queue<vyx> pq;
void inp() {
  scanf("%d %d", &r, &c);
  char cv[MX + 1];
  for (y = 0; y < r; y++) {
    scanf("%s", cv);
    for (x = 0; x < c; x++) {
      if (cv[x] == 'X')
        vv[y][x] = -1;
      else {
        bv[y][x] = 1;
        q.push({y, x});
        if (cv[x] == 'L') {
          pq.push({-1, y, x});
          vv[y][x] = -2;
        } else
          vv[y][x] = 0;
      }
    }
  }
}

void clc() {
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    t = vv[y][x] < 0 ? 0 : vv[y][x];
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c || bv[ny][nx]) continue;
      bv[ny][nx] = 1;
      if (!vv[ny][nx]) continue;
      if (vv[ny][nx] != -2) vv[ny][nx] = t + 1;
      q.push({ny, nx});
    }
  }
}

int bfs() {
  memset(bv, 0, sizeof bv);
  pq.pop();
  bv[pq.top().y][pq.top().x] = 1;
  while (!pq.empty()) {
    y = pq.top().y, x = pq.top().x, t = pq.top().v;
    pq.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c || bv[ny][nx]) continue;
      bv[ny][nx] = 1;
      if (vv[ny][nx] == -2) return t;
      pq.push({max(t, vv[ny][nx]), ny, nx});
    }
  }
  return -1;
}

int main() {
  inp();
  clc();
  printf("%d", bfs());
}