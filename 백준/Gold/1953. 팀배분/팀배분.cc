#include <cstdio>
#include <queue>

std::queue<int> q;
bool bv[101][101];
int n, v[101], r;
void bfs(int s) {
  int e;
  q.push({s});
  v[s] = 1, ++r;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    for (e = 1; e <= n; e++) {
      if (!bv[s][e] || v[e]) continue;
      v[e] = (v[s] & 1) ? 2 : 1;
      if (v[e] & 1) ++r;
      q.push(e);
    }
  }
}

int main() {
  int c, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c);
    while (c--) {
      scanf("%d", &m);
      bv[i][m] = bv[m][i] = 1;
    }
  }

  for (int i = 1; i <= n; i++) if (!v[i]) bfs(i);

  printf("%d\n", r);
  for (int i = 1; i <= n; i++) if (v[i] & 1) printf("%d ", i);
  printf("\n%d\n", n - r);
  for (int i = 1; i <= n; i++) if (v[i] & 2) printf("%d ", i);
}