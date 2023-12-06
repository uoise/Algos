#include <cstdio>
#include <vector>

constexpr int MX = 1e5 + 1;
std::vector<int> pv[MX];
int vv[MX];
void dfs(int c, int v) {
  vv[c] += v;
  for (const int& n : pv[c]) dfs(n, vv[c]);
}

int main() {
  int n, m, x, w;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x > 0) pv[x].push_back(i);
  }
  while (m--) {
    scanf("%d %d", &x, &w);
    vv[x] += w;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", vv[i]);
}