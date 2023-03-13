#include <cstdio>
#include <queue>
#include <unordered_set>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, MX = 1000;
unordered_set<int> p;
queue<pair<int, int>> q;
int n, m, c, vv[MX][MX], wv[MX * MX];
int ny, nx;
void bfs(int y, int x) {
  wv[++c] = 1;
  vv[y][x] = c;
  q.push({y, x});
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || vv[ny][nx]) continue;
      vv[ny][nx] = vv[y][x];
      ++wv[vv[ny][nx]];
      q.push({ny, nx});
    }
  }
}

void inp() {
  scanf("%d %d", &n, &m);
  char s[1001];
  for (int y = 0; y < n; y++) {
    scanf("%s", s);
    for (int x = 0; x < m; x++) vv[y][x] = s[x] == '1' ? -1 : 0;
  }
}

int main() {
  inp();
  int y, x, d;
  for (y = 0; y < n; y++)
    for (x = 0; x < m; x++)
      if (!vv[y][x]) bfs(y, x);

  for (y = 0; y < n; y++) {
    for (x = 0; x < m; x++) {
      c = 0;
      if (vv[y][x] < 0) {
        ++c;
        for (d = 0; d < 4; d++) {
          ny = y + yy[d], nx = x + xx[d];
          if (ny < 0 || ny >= n || nx < 0 || nx >= m || vv[ny][nx] < 0)
            continue;
          p.insert(vv[ny][nx]);
        }
        for (auto it = p.begin(); it != p.end(); it++) c += wv[*it];
        p.clear();
      }
      printf("%d", c % 10);
    }
    printf("\n");
  }
}