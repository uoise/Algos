#include <cstdio>

bool b[101], q[101];
int v[101], n, r;
void dfs(int s, int c) {
  b[c] = 1;
  if (s == v[c]) q[s] = 1, ++r;
  if (!b[v[c]]) dfs(s, v[c]);
  b[c] = 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) dfs(i, i);
  printf("%d\n", r);
  for (int i = 1; i <= n; i++) if (q[i]) printf("%d\n", i);
}