#include <cstdio>
#include <cstring>
#include <queue>

struct cuv {
  int c, u, v;
  bool operator<(const cuv& o) const { return c > o.c; }
};

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

std::priority_queue<cuv> pq;
bool bv[51][51];
char s[51];
int n, dv[51][51];
int main() {
  int y, x, w, ny, nx, d;
  memset(dv, 0x3f, sizeof dv);
  scanf("%d", &n);
  for (y = 0; y < n; y++) {
    scanf("%s", s);
    for (x = 0; x < n; x++) bv[y][x] = s[x] == '0';
  }

  dv[0][0] = 0;
  pq.push({dv[0][0], 0, 0});
  while (!pq.empty()) {
    y = pq.top().u, x = pq.top().v, w = pq.top().c;
    pq.pop();
    if (w > dv[y][x]) continue;
    for (d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (dv[ny][nx] <= dv[y][x] + bv[ny][nx]) continue;
      dv[ny][nx] = dv[y][x] + bv[ny][nx];
      pq.push({dv[ny][nx], ny, nx});
    }
  }

  printf("%d", dv[n - 1][n - 1]);
}