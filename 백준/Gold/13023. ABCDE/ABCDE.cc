#include <cstdio>
#include <vector>

int n, m, x, y, r;
bool bv[2001];
std::vector<int> v[2001];
void dfs(const int& c, const int& d) {
  if (d == 5) {
    r = 1;
    return;
  }

  bv[c] = 1;
  for (const auto& i : v[c]) {
    if (r) break;
    if (!bv[i]) dfs(i, d + 1);
  }
  bv[c] = 0;
}

int main() {
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for (int i = 0; i < n && !r; i++) dfs(i, 1);

  printf("%d", r);
}