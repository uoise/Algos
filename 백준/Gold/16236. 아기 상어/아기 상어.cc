#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct yxl {
  int y, x, l;
  bool operator<(const yxl& a) const {
    return l == a.l ? y == a.y ? x > a.x : y > a.y : l > a.l;
  }
};

int vv[20][20], bv[20][20], n;
constexpr int xx[] = {0, -1, 1, 0}, yy[] = {-1, 0, 0, 1};  // u -> l -> r ->d
priority_queue<yxl> pq;
int sol() {
  int res = 0, cnt = 1, siz = 2, ate = 0, len;
  int cx, cy, nx, ny;  // cur, nxt
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &vv[i][j]);
      if (vv[i][j] == 9) {
        bv[i][j] = cnt, vv[i][j] = 0;
        pq.push({i, j, 0});
      }
    }

  while (!pq.empty()) {
    cy = pq.top().y, cx = pq.top().x, len = pq.top().l;
    pq.pop();
    if (vv[cy][cx] && (vv[cy][cx] < siz)) {
      pq = priority_queue<yxl>();
      res += len;
      vv[cy][cx] = 0, ++cnt;
      if (++ate == siz) ++siz, ate = 0;
      pq.push({cy, cx, 0});
    } else {
      for (int i = 0; i < 4; i++) {
        ny = cy + yy[i], nx = cx + xx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (bv[ny][nx] != cnt && vv[ny][nx] <= siz) {
          bv[ny][nx] = cnt;
          pq.push({ny, nx, len + 1});
        }
      }
    }
  }

  return res;
}

int main() {
  scanf("%d", &n);
  printf("%d", sol());
}
