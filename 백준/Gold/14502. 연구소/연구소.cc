#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> vv, cv;
queue<pair<int, int>> q;
int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1}, n, m, s, res;
void inp() {
  cin >> n >> m;
  vv.assign(n, vector<int>(m, 0));
  for (auto& v : vv)
    for (auto& i : v) {
      cin >> i;
      if (!i) s++;
    }
}

void bfs() {
  cv = vv;
  int cnt = s - 3;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (cv[i][j] == 2) q.push({i, j});

  while (!q.empty()) {
    const int cy = q.front().first, cx = q.front().second;
    q.pop();
    for (int p = 0; p < 4; p++) {
      const int ny = cy + yy[p], nx = cx + xx[p];
      if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
        if (!cv[ny][nx]) {
          cv[ny][nx] = 4;
          if (--cnt <= res) {
            q = queue<pair<int, int>>();
            break;
          }
          q.push({ny, nx});
        }
      }
    }
  }
  res = max(res, cnt);
}

void btr(int y, int x, int c) {
  vv[y][x] = 3;
  if (c == 3) {
    bfs();
  } else {
    int i = y, j = x;
    while (1) {
      if (++j == m) j = 0, ++i;
      if (i == n) break;
      if (!vv[i][j]) btr(i, j, c + 1);
    }
  }
  vv[y][x] = 0;
}

int sol() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vv[i][j]) btr(i, j, 1);
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  inp();
  cout << sol();
}