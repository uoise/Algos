#include <algorithm>
#include <cstdio>
#include <vector>

constexpr int MN = 1e6 + 1;
std::vector<int> v[MN];
int n, s, w[MN], m = 3e6, l = 0, r = 0;
void dfs(int c, int p) {
  for (const int& a : v[c]) {
    if (a == p) continue;
    dfs(a, c);
    w[c] += w[a];
  }

  int t = abs(s - w[c] * 2);
  if (t < m) m = t, l = c, r = p;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    s += w[i];
  }

  dfs(1, 0);
  printf("%d\n%d %d", m, l, r);
}