#include <cstdio>
#include <queue>
#include <vector>

std::vector<std::vector<int>> bv;
std::vector<int> dv;
std::queue<int> q;
int n, m, k, x, s, e;
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &x);
  bv.assign(n + 1, std::vector<int>());
  dv.assign(n + 1, 0);
  while (m--) {
    scanf("%d %d", &s, &e);
    bv[s].push_back(e);
  }
  ++k;
  dv[x] = 1;
  q.push(x);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    if (dv[x] > k) continue;
    for (const int& nxt : bv[x]) {
      if (dv[nxt]) continue;
      dv[nxt] = dv[x] + 1;
      q.push(nxt);
    }
  }
  m = 0;
  for (int i = 1; i <= n; i++)
    if (dv[i] == k) {
      printf("%d\n", i);
      m = 1;
    }
  if (!m) printf("-1");
}