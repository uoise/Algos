#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};
char vv[100][101];
bool bv[100][100];
int n, r, s;
void bfs(int y, int x, int g = 0) {
  char clr = vv[y][x];
  if (g && (clr == 'R' || clr == 'G')) clr = 'X';
  q.push({y, x});
  bv[y][x] = 1;
  while (!q.empty()) {
    int cy = q.front().first, cx = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = cy + yy[i], nx = cx + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (bv[ny][nx]) continue;
      if ((clr == 'X') && (vv[ny][nx] == 'R' || vv[ny][nx] == 'G')) {
        q.push({ny, nx});
        bv[ny][nx] = 1;
      } else if (clr == vv[ny][nx]) {
        q.push({ny, nx});
        bv[ny][nx] = 1;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", vv[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!bv[i][j]) bfs(i, j), ++r;

  memset(bv, 0, sizeof bv);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!bv[i][j]) bfs(i, j, 1), ++s;
  printf("%d %d", r, s);
}