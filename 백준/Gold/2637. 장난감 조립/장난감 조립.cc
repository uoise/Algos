#include <cstdio>
#include <queue>
#include <vector>

std::queue<int> q;
std::vector<std::pair<int, int>> vv[101];
int n, bv[101], rv[101];
int main() {
  int m, x, y, k;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %d", &x, &y, &k);
    vv[x].push_back({y, k});
    ++bv[y];
  }

  q.push(n);
  rv[n] = 1;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (const auto& p : vv[x]) {
      rv[p.first] += rv[x] * p.second;
      if (!--bv[p.first]) q.push(p.first);
    }
  }

  for (int i = 1; i <= n; i++)
    if (vv[i].empty()) printf("%d %d\n", i, rv[i]);
}