#include <cstdio>
#include <cstring>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

constexpr int MX = 50, INF = 0x3f3f3f3f;
constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, m, vv[MX][MX], tv[MX][MX], dv[MX * MX + 1][MX * MX + 1], gv[MX * MX + 1];
std::priority_queue<cuv> pq;
std::queue<cuv> q, oq;
void inp() {
  char s[MX + 1];
  memset(vv, 0x3f, sizeof vv);
  scanf("%d %d", &n, &m);
  ++m;
  int idx = -1;
  for (int y = 0; y < n; y++) {
    scanf("%s", s);
    for (int x = 0; x < n; x++) {
      if (s[x] == '1') continue;
      if (s[x] == '0') {
        vv[y][x] = 0;
      } else {
        vv[y][x] = (s[x] == 'S') ? -1 : --idx;
        oq.push({-vv[y][x], y, x});
      }
    }
  }
}

void bfs(const int idx, int y, int x) {
  int c, ny, nx;
  memcpy(tv, vv, sizeof vv);
  q.push({tv[y][x] = 1, y, x});
  while (!q.empty()) {
    c = q.front().c + 1, y = q.front().u, x = q.front().v;
    q.pop();
    for (int d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (tv[ny][nx] > 0) continue;
      const int nxt = -tv[ny][nx];
      q.push({tv[ny][nx] = c, ny, nx});
      if (!nxt || dv[idx][nxt]) continue;
      dv[idx][nxt] = dv[nxt][idx] = c - 1;
      pq.push({dv[idx][nxt], idx, nxt});
    }
  }
}

int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  gv[x] = y;
  return 1;
}

int unf() {
  for (int i = 1; i <= m; i++) gv[i] = i;
  int r = 0, cnt = 0;
  while (!pq.empty() && cnt < m) {
    if (mks(pq.top().u, pq.top().v)) r += pq.top().c, ++cnt;
    pq.pop();
  }
  int tgt = fnd(1);
  for (int i = 1; i <= m; i++)
    if (tgt != fnd(i)) return -1;
  return r;
}

int main() {
  inp();
  while (!oq.empty()) {
    bfs(oq.front().c, oq.front().u, oq.front().v);
    oq.pop();
  }
  printf("%d", unf());
}