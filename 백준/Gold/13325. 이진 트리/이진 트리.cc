#include <algorithm>
#include <cstdio>

int k, s, vv[(1 << 21) + 1];
int dfs(int c, int h) {
  if (h++ >= k) return 0;
  int l = vv[c * 2] + dfs(c * 2, h), r = vv[c * 2 + 1] + dfs(c * 2 + 1, h);
  if (l > r) vv[c * 2 + 1] += (l - r);
  else vv[c * 2] += (r - l);
  return std::max(l, r);
}

int main() {
  scanf("%d", &k);
  for (int i = 2; i < (1 << (k + 1)); i++) scanf("%d", &vv[i]);
  dfs(1, 0);
  for (int i = 1; i < (1 << (k + 1)); i++) s += vv[i];
  printf("%d", s);
}