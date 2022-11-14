#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
using iip = pair<int, int>;
constexpr int MX = 101, GX = 7, INF = 0x3f3f3f3f;
int mv[MX][MX], gv[GX][GX], xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1}, pv[GX];
bool bv[MX][MX];
vector<tuple<int, int, int>> ev;
queue<iip> q;
iip cv[7];
int N, M, C;

void bfs(const iip bb) {
  q.push({bb.first, bb.second});
  while (!q.empty()) {
    int cx = q.front().first, cy = q.front().second;
    mv[cy][cx] = C;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cx + xx[i], ny = cy + yy[i];
      if ((nx >= 0 && nx < M) && (ny >= 0 && ny < N) && (mv[ny][nx] == -1))
        q.push({nx, ny});
    }
  }
}

void len(const iip bb, const int clr) {
  q.push({bb.first, bb.second});
  while (!q.empty()) {
    int cx = q.front().first, cy = q.front().second;
    bv[cy][cx] = 1;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cx + xx[i], ny = cy + yy[i];
      if ((nx >= 0 && nx < M) && (ny >= 0 && ny < N)) {
        if (mv[ny][nx] == clr && !bv[ny][nx])
          q.push({nx, ny});
        else if (!mv[ny][nx]) {
          int cnt = 1;
          int dx = nx, dy = ny;
          while (dx >= 0 && dx < M && dy >= 0 && dy < N) {
            if (mv[dy][dx]) {
              if (mv[dy][dx] == clr || cnt <= 2) break;
              gv[clr][mv[dy][dx]] = min(gv[clr][mv[dy][dx]], cnt - 1);
              break;
            }
            dx += xx[i], dy += yy[i], ++cnt;
          }
        }
      }
    }
  }
}

int fnd(int x) {
  if (x == pv[x]) return x;
  return pv[x] = fnd(pv[x]);
}
int sol() {
  for (int y = 0; y < N; y++)
    for (int x = 0; x < M; x++)
      if (mv[y][x] == -1) bfs(cv[++C] = {x, y});  // setColor

  for (int i = 1; i <= C; i++) {
    len(cv[i], i);  // getLen
    pv[i] = i;
  }

  for (int i = 1; i <= C; i++)
    for (int j = 1; j <= C; j++)
      if (gv[i][j] != INF) ev.push_back({gv[i][j], i, j});
  sort(ev.begin(), ev.end());  // makeEdge

  int res = 0;
  for (const auto& cc : ev) { 
    int cb = fnd(get<1>(cc)), ce = fnd(get<2>(cc));
    if (cb != ce) {
      res += get<0>(cc);
      pv[cb] = ce;
    }
  } // unf

  for (int i = 1; i < C; i++)
    if (fnd(i) != fnd(i + 1)) return -1;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(gv, 0x3f, sizeof gv);
  cin >> N >> M;
  for (int y = 0; y < N; y++)
    for (int x = 0; x < M; x++) {
      cin >> mv[y][x];
      mv[y][x] *= -1;
    }
  cout << sol();
}
