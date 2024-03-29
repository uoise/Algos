#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, m, s, r, c, vv[100][100], ny, nx;
bool bv[100][100];
queue<pair<int, int>> q;
void chk() {
  int y, x, cnt = 0;
  q.push({0, 0});
  vv[0][0] = -1, bv[0][0] = 1;
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (vv[ny][nx] < 1 && !bv[ny][nx]) {
        vv[ny][nx] = -1, bv[ny][nx] = 1;
        q.push({ny, nx});
      }
    }
  }
  memset(bv, 0, sizeof bv);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &vv[i][j]);
      if (vv[i][j]) ++s;
    }

  while (s) {
    ++r;
    chk();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (vv[i][j] != 1) continue;
        c = 0;
        for (int k = 0; k < 4; k++) {
          ny = i + yy[k], nx = j + xx[k];
          if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
          if (vv[ny][nx] == -1) ++c;
        }
        if (c > 1) vv[i][j] = 2;
      }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (vv[i][j] == 2) vv[i][j] = 0, --s;
  }
  printf("%d", r);
}