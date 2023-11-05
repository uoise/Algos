#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

constexpr int MX = 1e5 + 1;

std::vector<int> vv[MX];
std::queue<std::pair<int, int>> q;
bool bv[MX];
int bfs(int s, int e) {
  int c, w;
  memset(bv, 0, sizeof bv);
  while (!q.empty()) q.pop();
  bv[s] = 1;
  q.push({s, 1});
  while (!q.empty()) {
    c = q.front().first, w = q.front().second;
    q.pop();
    if (c == e) return w;
    for (const int& i : vv[c]) {
      if (bv[i]) continue;
      bv[i] = 1;
      q.push({i, w + 1});
    }
  }

  return 0;
}

int main() {
  int n, s, c, h;
  scanf("%d %d %d %d", &n, &s, &c, &h);
  while (--n) {
    int a, b;
    scanf("%d %d", &a, &b);
    vv[a].push_back(b);
    vv[b].push_back(a);
  }

  long long fl = bfs(s, c) + bfs(c, h) - 1, sl = bfs(s, h);
  long long dl = (fl - sl) / 2;
  printf("%lld", ((fl - dl) * (fl - dl - 1) + dl * (dl + 1)) / 2);
}