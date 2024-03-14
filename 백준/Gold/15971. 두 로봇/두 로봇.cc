#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
constexpr int MX = 1e5 + 1;
vector<pair<int, int>> v[MX];

bool bv[MX];
int s, e, r;
void dfs(int c, int w, int x) {
  bv[c] = 1;
  if (c == e) {
    r = w - x;
    return;
  }

  for (auto [a, u] : v[c]) {
    if (bv[a]) continue;
    dfs(a, w + u, max(x, u));
  }
}

int main() {
  int n, a, b, c;
  scanf("%d %d %d", &n, &s, &e);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &a, &b, &c);
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  dfs(s, 0, 0);
  printf("%d", r);
}