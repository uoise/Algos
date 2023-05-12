#include <cstdio>
#include <queue>

constexpr int MX = 32001;
std::queue<int> sq[MX];
int n, m, u, v, vv[MX];
int main() {
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &u, &v);
    vv[v]++;
    sq[u].push(v);
  }

  while (1) {
    m = 0;
    for (int i = 1; i <= n; i++) {
      if (vv[i]) continue;
      m = i;
      break;
    }
    if (!m) break;
    printf("%d ", m);
    vv[m] = -1;

    while (!sq[m].empty()) {
      vv[sq[m].front()]--;
      sq[m].pop();
    }
  }
}