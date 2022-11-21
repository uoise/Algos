#include <cstdio>
#include <cstring>

int vv[1001];
bool bv[1001];
void dfs(int cur) {
  int nxt = vv[cur];
  vv[cur] = cur, bv[cur] = 1;
  if (cur == nxt) return;
  dfs(nxt);
}

int sol(const int n) {
  int res = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &vv[i]);
  for (int i = 1; i <= n; i++)
    if (!bv[i]) dfs(i), ++res;
  return res;
}

int main() {
  int T, n, r;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(bv, 0, sizeof bv);
    printf("%d\n", sol(n));
  }
}