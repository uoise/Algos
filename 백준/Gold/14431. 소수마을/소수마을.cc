#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#define x first
#define y second

using namespace std;
using iip = pair<int, int>;
constexpr int INF = 2e9, siz = 4002;
vector<vector<iip>> vv;
vector<int> rv;
bool pr[siz * 2] = {1, 1};
int n;

void init() {
  int bx, by, ex, ey;
  scanf("%d %d %d %d %d", &bx, &by, &ex, &ey, &n);
  rv.assign(n + 2, INF);
  iip pv[n + 2];

  vv.assign(n + 2, vector<iip>());
  pv[0] = {bx, by}, pv[n + 1] = {ex, ey};
  for (int i = 1; i <= n; i++) scanf("%d %d", &pv[i].x, &pv[i].y);

  for (int i = 2; i <= siz * 2; i++)
    if (!pr[i])
      for (int j = 2 * i; j <= siz * 2; j += i) pr[j] = 1;

  for (int i = 0; i < n + 2; i++) {
    for (int j = i + 1; j < n + 2; j++) {
      int xx = pv[i].x - pv[j].x;
      int yy = pv[i].y - pv[j].y;
      xx = xx * xx + yy * yy;
      xx = sqrt(xx);
      if (!pr[xx]) {
        vv[i].push_back({j, xx});
        vv[j].push_back({i, xx});
      }
    }
  }
}

void djs() {
  priority_queue<iip> pq;
  rv[0] = 0;
  pq.push({-rv[0], 0});
  while (!pq.empty()) {
    int cst = -pq.top().x, cur = pq.top().y;
    pq.pop();
    for (const auto& p : vv[cur]) {
      if (rv[p.x] > cst + p.y) {
        rv[p.x] = cst + p.y;
        pq.push({-rv[p.x], p.x});
      }
    }
  }
}

int main() {
  init();
  djs();
  printf("%d", (rv[n + 1] == INF ? -1 : rv[n + 1]));
}