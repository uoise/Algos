#include <cstdio>
#include <queue>

constexpr int MX = 1001, yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

struct yxw {
  int y, x, w;
};

std::queue<yxw> qv[10], t;
int n, m, p, sv[10], vv[MX][MX], rv[10];
bool bfs(const int c, std::queue<yxw>& q) {
  int r = 0;
  while (!q.empty()) {
    int y = q.front().y, x = q.front().x, w = q.front().w - 1;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (vv[ny][nx]) continue;
      ++r, vv[ny][nx] = c;
      if (!w)
        t.push({ny, nx, sv[c]});
      else
        q.push({ny, nx, w});
    }
  }

  rv[c] += r;
  q = t;
  while (!t.empty()) t.pop();

  return r;
}

int main() {
  char inp[MX];
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 1; i <= p; i++) scanf("%d", &sv[i]);
  for (int y = 0; y < n; y++) {
    scanf("%s", &inp);
    for (int x = 0; x < m; x++) {
      int v = inp[x] == '#' ? -1 : (inp[x] == '.' ? 0 : (inp[x] - '0'));
      vv[y][x] = v;
      if (v < 1) continue;
      qv[v].push({y, x, sv[v]});
      ++rv[v];
    }
  }

  bool chk = true;
  while (chk) {
    chk = false;
    for (int i = 1; i <= p; i++)
      if (!qv[i].empty()) chk |= bfs(i, qv[i]);
  }

  for (int i = 1; i <= p; i++) printf("%d ", rv[i]);
}