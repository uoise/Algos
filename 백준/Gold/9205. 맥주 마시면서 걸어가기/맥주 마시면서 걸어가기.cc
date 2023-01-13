#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int n, x, y, vv[102][2];
bool bv[102];
bool sol() {
  bv[0] = 1;
  q.push({vv[0][0], vv[0][1]});
  while (!q.empty()) {
    x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 1; i < n + 2; i++) {
      if (!bv[i] && abs(x - vv[i][0]) + abs(y - vv[i][1]) < 1001) {
        if (i == n + 1) return 1;
        bv[i] = 1;
        q.push({vv[i][0], vv[i][1]});
      }
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n + 2; i++) scanf("%d %d", &vv[i][0], &vv[i][1]);
    printf("%s\n", (sol() ? "happy" : "sad"));
    memset(bv, 0, sizeof bv);
    while (!q.empty()) q.pop();
  }
}