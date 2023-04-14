#include <cstdio>
#include <queue>
#include <unordered_set>

constexpr int MX = 1001;

std::unordered_set<int> sv[MX];
std::queue<int> q;
int n, m, u, v, r, rv[MX], vv[MX];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    vv[v]++;
    sv[u].insert(v);
  }

  while (++r) {
    for (int i = 1; i <= n; i++) {
      if (!vv[i]) {
        q.push(i);
        rv[i] = r, vv[i] = -1;
      }
    }
    if (q.empty()) break;
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      for (auto it = sv[c].begin(); it != sv[c].end(); it++) vv[*it]--;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", rv[i]);
}